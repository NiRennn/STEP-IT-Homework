using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using GalaSoft.MvvmLight.Views;
using MonefyApp.Messages;
using MonefyApp.Service.Classes;
using MonefyApp.Service.Interfaces;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace MonefyApp.ViewModels
{
    class CalculatorViewModel : ViewModelBase , INotifyPropertyChanged
    {
        private readonly IMessenger _messenger;

        private readonly NavigationService _navigationService;
        
        private readonly IDataService _dataService;



        bool operatorPressed = false;
        bool equalPressed = false;


        private string _textBox1;
        private string _textBox2;
        private string _descriptionTextBox;


        private Button MyBtn = new();
        private string buttonName;

        private string CurrentDate;
        private Color Color;


        public string TextBox1
        {
            get => _textBox1;
            set
            {
                if (_textBox1 != value)
                {
                    _textBox1 = value;
                    RaisePropertyChanged(nameof(TextBox1));
                }
            } 
        }
        public string TextBox2
        {
            get => _textBox2;
            set
            {
                if (_textBox2 != value)
                {
                    _textBox2 = value;
                    RaisePropertyChanged(nameof(TextBox2));
                }
            }
        }
        public string DescriptionTextBox
        {
            get => _descriptionTextBox;
            set
            {
                if (_descriptionTextBox != value)
                {
                    _descriptionTextBox = value;
                    RaisePropertyChanged(nameof(DescriptionTextBox));
                }
            }
        }


        public CalculatorViewModel(IMessenger messenger, NavigationService navigationService, IDataService dataService)
        {
            _dataService = dataService;
            _messenger = messenger;
            TextBox2 = string.Empty;
            _navigationService = navigationService;


            _messenger.Register<ButtonMessage>(this, (message) =>
            {
                MyBtn = message.Data;

            });

            _messenger.Register<DateMessege>(this, (message) =>
            {
                CurrentDate = message.Date;
            });

        }


        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void RaisePropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        public void DoCalculation()
        {
            double ans = 0;
            char sign = ' ';
            if (!string.IsNullOrEmpty(TextBox1))
            {
                sign = TextBox1[TextBox1.Length - 1];
            }
            if (double.TryParse(TextBox1.Substring(0, TextBox1.Length - 1), out double value1) && double.TryParse(TextBox2, out double value2))
            {
                switch (sign)
                {
                    case '+':
                        ans = double.Parse(TextBox1.Substring(0, TextBox1.Length - 1)) + double.Parse(TextBox2);
                        break;
                    case '-':
                        ans = double.Parse(TextBox1.Substring(0, TextBox1.Length - 1)) - double.Parse(TextBox2);
                        break;
                    case '/':
                        ans = double.Parse(TextBox1.Substring(0, TextBox1.Length - 1)) / double.Parse(TextBox2);
                        break;
                    case 'x':
                        ans = double.Parse(TextBox1.Substring(0, TextBox1.Length - 1)) * double.Parse(TextBox2);
                        break;
                    default:
                        break;
                }
                TextBox2 = $"{ans}";
            }
        }

        public ButtonCommand<Button> Button_Click
        {
            get => new((button) => {
                if (TextBox2 == "Ошибка!")
                {
                    TextBox2 = "";
                }
                if (equalPressed)
                {
                    TextBox2 = "";
                }
                if (operatorPressed)
                {
                    TextBox2 = button.Content.ToString();
                }
                else
                {
                    TextBox2 += button.Content;
                }
                operatorPressed = false;
                equalPressed = false;
            });
        }



        public ButtonCommand<Button>OperatorButton_Click
        {
            get => new((button) =>
            {
                TextBox2 += button.Content.ToString();
                TextBox1 = new string(TextBox2);

                if (TextBox1 != "")
                {
                    DoCalculation();
                }

                operatorPressed = true;
                equalPressed = false;
            });
        }

        public RelayCommand EqualButton_Click
        {
            get => new(() =>
            {
                if (TextBox2 == "0")
                {
                    TextBox2 = "Ошибка!";
                }
                if (!operatorPressed && !equalPressed)
                {
                    string last_text = TextBox2;
                    DoCalculation();

                    TextBox1 = null;
                    operatorPressed = true;
                    equalPressed = true;
                }
            });
        }

        public RelayCommand DeleteButton_Click
        {
            get => new(() => {
                if (TextBox2.Length > 0)
                {
                    TextBox2 = TextBox2.Remove(TextBox2.Length - 1);
                }
                else
                {
                    TextBox2 = string.Empty;
                }
            });
        }

        public RelayCommand AddToDiagram
        {
            get => new(() =>
            {
                if(MyBtn.Name == "Plus")
                {
                    _dataService.SendData(TextBox2);

                }
                else if(MyBtn.Name == "Minus")
                {
                    _dataService.SendOtherExpenses(TextBox2,DescriptionTextBox,CurrentDate);
                }
                else
                {
                    _dataService.SendValueName(TextBox2, MyBtn, DescriptionTextBox,CurrentDate,Color);
                }
                TextBox1 = string.Empty;
                TextBox2 = string.Empty;
                DescriptionTextBox = string.Empty;
                _navigationService.NavigateTo<DiagramViewModel>();
            });
        }

        
        public RelayCommand BackToMainButton
        {
            get => new(() =>
            {
                TextBox1 = string.Empty;
                TextBox2 = string.Empty;
                DescriptionTextBox = string.Empty;
                _navigationService.NavigateTo<DiagramViewModel>();
            });
        }
    }







}

