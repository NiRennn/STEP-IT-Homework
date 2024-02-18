using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using TrendyolApp.Model;

namespace TrendyolApp.ViewModel
{
    public class BalanceViewModel : ViewModelBase
    {

        private readonly CurrentUser _currentUser;
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
        public BalanceViewModel(CurrentUser currentUser)
        {
            _currentUser = currentUser;
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

    }
}
