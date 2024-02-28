using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Views;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using TrendyolApp.Model;
using TrendyolApp.Service.Interfaces;


namespace TrendyolApp.ViewModel
{
    public class BalanceViewModel : ViewModelBase
    {

        private readonly CurrentUser _currentUser;
        private readonly Service.Interfaces.INavigationService navigationService;

        TrendyolDbContext _trendyoulDB = new TrendyolDbContext();

        private string AddToBalanceTextBox;

        public string TextBox1
        {
            get => AddToBalanceTextBox;
            set
            {
                if (AddToBalanceTextBox != value)
                {
                    AddToBalanceTextBox = value;
                    RaisePropertyChanged(nameof(TextBox1));
                }
            }
        }
        public BalanceViewModel(CurrentUser currentUser, Service.Interfaces.INavigationService navigation)
        {
            _currentUser = currentUser;
            navigationService = navigation;

        }


        public string BalanceInfo => _currentUser.Balance.ToString();


        public RelayCommand AddToBalance
        {
            get => new(() =>
            {
                if (float.TryParse(AddToBalanceTextBox, out float amountToAdd))
                {
                    _currentUser.Balance += amountToAdd;


                    var user = _trendyoulDB.Users.FirstOrDefault(u => u.Username == _currentUser.UserName);
                    if (user != null)
                    {
                        user.Balance = _currentUser.Balance;
                        _trendyoulDB.SaveChanges();
                    }
                    RaisePropertyChanged(nameof(BalanceInfo));
                }
                else
                {
                    MessageBox.Show("Incorrect value for replenishing the balance.");
                }
                TextBox1 = string.Empty;
            });
        }

        public RelayCommand BackToUserIntarface
        {
            get => new(() =>
            {
                navigationService.NavigateTo<UserUCViewModel>();
            });
        }

    }
}
