using GalaSoft.MvvmLight.Messaging;
using NumbersGenerator.Interfaces;
using NumbersGenerator.Services;
using NumbersGenerator.ViewModels;
using NumbersGenerator.Views;
using SimpleInjector;
using System.Configuration;
using System.Data;
using System.Windows;

namespace NumbersGenerator
{

    public partial class App : Application
    {


        public static Container Container { get; set; } = new Container();

        public static MainWindowView window = new();


        public void Register()
        {
            Container.RegisterSingleton<IMessenger, Messenger>();
            Container.RegisterSingleton<INavigationService, NavigationService>();
            Container.RegisterSingleton<IDataService, DataService>();

            Container.RegisterSingleton<MainWindowViewModel>();

            Container.RegisterSingleton<FirstTaskViewModel>();
            Container.RegisterSingleton<SecondTaskViewModel>();
            Container.RegisterSingleton<ThirdTaskViewModel>();
            Container.RegisterSingleton<FourthTaskViewModel>();
            Container.RegisterSingleton<FifthTaskViewModel>();



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
