using LogonPasswordApp.Model;
using LogonPasswordApp.View;
using LogonPasswordApp.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LogonPasswordApp
{

    public partial class MainWindow : Window
    {
        private LoginViewModel loginViewModel;
        private RegisterViewModel registerViewModel;

        public MainWindow()
        {
            InitializeComponent();
            loginViewModel = new LoginViewModel();
            registerViewModel = new RegisterViewModel();

        }
        private void Login_Click(object sender, RoutedEventArgs e)
        {
            string username = UsernameTextBox.Text;
            string password = PasswordTextBox.Password;


            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
            {
                MessageBox.Show("Please, fill both fields.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            loginViewModel.LoginMethod(username, password);

        }
        private void Register_Click(object sender, RoutedEventArgs e)
        {
            string username = UsernameTextBox.Text;
            string password = PasswordTextBox.Password;


            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
            {
                MessageBox.Show("Please, fill both fields.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            registerViewModel.RegisterMethod(username, password);


        }
        private void ForgotPassword_Click(object sender, RoutedEventArgs e)
        {
            Window ForgotPasswordWindow = new Window();
            ForgotPasswordWindow.Show();
        }

    }
}
