using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using LiveCharts;
using LiveCharts.Wpf;
using MonefyApp.Messages;
using MonefyApp.Models;
using MonefyApp.Service.Classes;
using MonefyApp.Service.Interfaces;
using System;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Ribbon.Primitives;
using System.Windows.Media;

namespace MonefyApp.ViewModels
{
    class DiagramViewModel : ViewModelBase
    {
        public PieChart pieChart;

        public PieChart PieChart
        {
            get => pieChart;
            set
            {
                Set(ref pieChart, value);
            }
        }


        private readonly INavigationService navigationService;
        private readonly IDataService _dataService;
        private readonly IMessenger _messenger;
        private readonly IJsonService _jsonService;


        private double _value;
        private double _blnc;
        private string _name;
        private double _otherExpences;
        private Button _button;
        private string _description;
        private DateTime _currentDate;
        private Color _color;

        int numberOfDaysToAdd = 1;



        private double _balance = 1000;
        public double Balance
        {
            get { return _balance; }
            set
            {
                Set(ref  _balance, value);
            }
        }

        ObservableCollection<Category> CategoriesList = new ObservableCollection<Category>();
        ObservableCollection<Expenses> ExpensesList = new ObservableCollection<Expenses>();

        public DateTime currentDate { get; set; }

        

        public DiagramViewModel(IDataService dataService, INavigationService navigation,IMessenger messenger,IJsonService jsonService)
        {
            //CategoriesList = jsonService.Deserialize<Category>("category.json");
            //ExpensesList = jsonService.Deserialize<Expenses>("expenses.json");

            currentDate = DateTime.Now;

            navigationService = navigation;
            _dataService = dataService;
            _messenger = messenger;


            PieChart = new();


            //для добавления доходов
            _messenger.Register<DataMessage>(this, (message) =>
            {
                Balance += _blnc;
            });


            //для добавления расходов по категориям
            _messenger.Register<ValueNameMessage>(this, (message) =>
            {
                _value = Convert.ToDouble(message.Value as string);
                _button = message.button;
                _description = message.Description as string;
                _currentDate = Convert.ToDateTime(message.Date);
                _color = ((SolidColorBrush)_button.Foreground).Color;

                Category newCategory = new Category(
                    name: _button.ToString(),
                    sum: _value,
                    date: _currentDate,
                    description: _description,
                    color: _color
                    );

                PieChart.Series.Add(new PieSeries()
                {
                    Fill = _button.Foreground,
                    Values = new ChartValues<double> { _value }
                });

                Balance -= _value;

                CategoriesList.Add(newCategory);
            });


            //для добавления трат не по категориям
            _messenger.Register<OtherExpensesMessage>(this, (message) =>
            {
                _otherExpences = Convert.ToDouble(message.Value as string);
                _description = message.Description as string;
                _currentDate = Convert.ToDateTime(message.Date);

                Expenses newExpenses = new Expenses(
                    sum: _otherExpences,
                    date: _currentDate,
                    description: _description
                    );

                PieChart.Series.Add(new PieSeries()
                {
                    Fill = new SolidColorBrush(Colors.OrangeRed),
                    Values = new ChartValues<double> { _otherExpences }
                });

                Balance -= _otherExpences;

                ExpensesList.Add(newExpenses) ;
            });

        }

        public RelayCommand<Button> AddExpense
        {
            get => new((button) =>
            {
                _dataService.SendButton(button);
                _dataService.SendDate(currentDate.ToString());
                navigationService.NavigateTo<CalculatorViewModel>();
            });
        }


        public RelayCommand<Button> ChangeDate
        {
            get => new((button) =>
            {
                PieChart.Series.Clear();

                if (button.Name == "increaseDate")
                {
                    currentDate = currentDate.AddDays(numberOfDaysToAdd);
                    RaisePropertyChanged(nameof(currentDate));
                    UpdateChartCategoriesForNewDate();
                    UpdateChartExpensesForNewDate();
                }
                else if (button.Name == "reduceDate")
                {
                    currentDate = currentDate.AddDays(-numberOfDaysToAdd);
                    RaisePropertyChanged(nameof(currentDate));
                    UpdateChartCategoriesForNewDate();
                    UpdateChartExpensesForNewDate();

                }
            });
        }

        private void UpdateChartCategoriesForNewDate() 
        {

            foreach(var item in CategoriesList)
            {

                if (item.Date.Date == currentDate.Date)
                {
                    PieChart.Series.Add(new PieSeries()
                    {
                        Fill = new SolidColorBrush(item.Color),
                        Values = new ChartValues<double> { item.CategorySum }
                    });
                }
            }
        }

        private void UpdateChartExpensesForNewDate()
        {
            foreach(var item in ExpensesList)
            {
                if (item.Date.Date == currentDate.Date) 
                {
                    PieChart.Series.Add(new PieSeries()
                    {
                        Fill = new SolidColorBrush(Colors.OrangeRed),
                        Values = new ChartValues<double> { item.CategorySum}
                    });
                }
            }
        }



    }
}
