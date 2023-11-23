using GalaSoft.MvvmLight.Messaging;
using MonefyApp.Service.Classes;
using MonefyApp.Service.Interfaces;
using MonefyApp.View;
using MonefyApp.ViewModels;
using SimpleInjector;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace MonefyApp
{

    public partial class App : Application
    {

        public static Container Container { get; set; } = new Container();

        public void Register()
        {
            Container.RegisterSingleton<IMessenger, Messenger>();
            Container.RegisterSingleton<INavigationService, NavigationService>();
            Container.RegisterSingleton<IDataService, DataService>();
            Container.RegisterSingleton<IJsonService, JsonService>();
            Container.RegisterSingleton<CalculatorViewModel>();
            Container.RegisterSingleton<MainWindowModel>();
            Container.RegisterSingleton<DiagramViewModel>();
            Container.RegisterSingleton<MenuViewModel>();
            Container.RegisterSingleton<MenuLeftViewModel>();
            Container.RegisterSingleton<NavigationService>();

            Container.Verify();

        }

        protected override void OnStartup(StartupEventArgs e)
        {
            Register();

            MainWindow window = new();

            window.DataContext = App.Container.GetInstance<MainWindowModel>();
            window.ShowDialog();
        }
    }
}
