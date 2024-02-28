using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using Microsoft.Identity.Client;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using TrendyolApp.Model;
using TrendyolApp.Service;
using TrendyolApp.Service.Interfaces;
using TrendyolApp.View;

namespace TrendyolApp.ViewModel
{
    class LoginViewModel : ViewModelBase
    {

        private readonly INavigationService navigationService;
        private readonly IDataService _dataService;
        private readonly IMessenger _messenger;

        private  CurrentUser _currentUser;

        TrendyolDbContext _trendyoulDB = new TrendyolDbContext();

        private string usernameTextBox;
        private string passwordTextBox;

        public string TextBox1
        {
            get => usernameTextBox;
            set
            {
                if (usernameTextBox != value)
                {
                    usernameTextBox = value;
                    RaisePropertyChanged(nameof(TextBox1));
                }
            }
        }
        public string TextBox2
        {
            get => passwordTextBox;
            set
            {
                if (passwordTextBox != value)
                {
                    passwordTextBox = value;
                    RaisePropertyChanged(nameof(TextBox2));
                }
            }
        }
        public LoginViewModel(IMessenger messenger,IDataService dataService,INavigationService navigation,CurrentUser currentUser)
        {
            navigationService = navigation;
            _dataService = dataService;
            _messenger = messenger;
            _currentUser = currentUser;
        }
        public RelayCommand DoRegistration
        {
            get => new(() =>
            {
                navigationService.NavigateTo<RegistrationViewModel>();
            });
        }

        public RelayCommand CompleteLogin
        {
            get => new(() =>
            {
                var user = _trendyoulDB.Users.FirstOrDefault(u => u.Username == TextBox1);

                if (user != null) 
                {
                    if (BCrypt.Net.BCrypt.Verify(TextBox2, user.Password))
                    {
                        if(user.Position == "SuperAdmin")
                        {
                            navigationService.NavigateTo<SuperAdminViewModel>();

                        }
                        else if(user.Position == "Admin")
                        {
                            navigationService.NavigateTo<AdminViewModel>();
                        }
                        else 
                        {
                            _currentUser.Id = user.Id;
                            _currentUser.UserName = user.Username;
                            _currentUser.Email = user.Email;
                            _currentUser.Balance = user.Balance;
                            _currentUser.Position = user.Position;

                            navigationService.NavigateTo<UserUCViewModel>();

                        }


                    }    

                
                }
                else
                {
                    MessageBox.Show("User not found.");
                }



            });
        }

        public RelayCommand ForgotPassword
        {
            get => new(() =>
            {
                navigationService.NavigateTo<ForgotPasswordViewModel>();
            });
        }



    }
}
