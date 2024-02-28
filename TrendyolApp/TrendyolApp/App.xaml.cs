using GalaSoft.MvvmLight.Messaging;
using SimpleInjector;
using System.Configuration;
using System.Data;
using System.Windows;
using System.Windows.Navigation;
using TrendyolApp.Model;
using TrendyolApp.Service;
using TrendyolApp.Service.Interfaces;
using TrendyolApp.View;
using TrendyolApp.ViewModel;

namespace TrendyolApp
{

    public partial class App : Application
    {
        public static Container Container { get; set; } = new Container();
        public static MainWindowView window = new();


        public void Register()
        {
            Container.RegisterSingleton<IMessenger, Messenger>();
            Container.RegisterSingleton<IDataService, DataService>();
            Container.RegisterSingleton<INavigationService, TrendyolApp.Service.NavigationService>();
            Container.RegisterSingleton<MainWindowViewModel>();


            Container.RegisterSingleton<CurrentUser>();


            Container.RegisterSingleton<LoginViewModel>();
            Container.RegisterSingleton<RegistrationViewModel>();
            Container.RegisterSingleton<AccountViewModel>();
            Container.RegisterSingleton<AccountInfoViewModel>();
            Container.RegisterSingleton<AdvertisingViewModel>();
            Container.RegisterSingleton<ForgotPasswordViewModel>();
            Container.RegisterSingleton<BalanceViewModel>();
            Container.RegisterSingleton<ShopViewModel>();
            Container.RegisterSingleton<OrdersViewModel>();
            Container.RegisterSingleton<SuperAdminViewModel>();
            Container.RegisterSingleton<AdminViewModel>();
            Container.RegisterSingleton<UserUCViewModel>();


            Container.Verify();
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            Register();

            window.DataContext = App.Container.GetInstance<MainWindowViewModel>();

            window.ShowDialog();
        }
    }
}
