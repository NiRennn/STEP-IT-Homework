using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using NumbersGenerator.Messages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NumbersGenerator.ViewModels
{
     class MainWindowViewModel : ViewModelBase
    {
        private ViewModelBase _currentView;

        private readonly Interfaces.INavigationService navigationService;
        public ViewModelBase CurrentView
        {
            get => _currentView;
            set
            {
                Set(ref _currentView, value);
            }
        }


        public MainWindowViewModel(IMessenger messenger, Interfaces.INavigationService _navigationService)
        {
            CurrentView = App.Container.GetInstance<FirstTaskViewModel>();

            navigationService = _navigationService;

            messenger.Register<NavigationMessage>(this, message =>
            {
                CurrentView = message.ViewModelType;
            });


        }

        public RelayCommand GoToSecondTask
        {
            get => new(() =>
            {
                CurrentView = App.Container.GetInstance<SecondTaskViewModel>();
            });
        }

        public RelayCommand GoToFirstTask
        {
            get => new(() =>
            {
                CurrentView = App.Container.GetInstance<FirstTaskViewModel>();
            });
        }

        public RelayCommand GoToThirdTask
        {
            get => new(() =>
            {
                CurrentView = App.Container.GetInstance<ThirdTaskViewModel>();
            });
        }

        public RelayCommand GoToFourthTask
        {
            get => new(() =>
            {
                CurrentView = App.Container.GetInstance<FourthTaskViewModel>();
            });
        }

        public RelayCommand GoToFifthTask
        {
            get => new(() =>
            {
                CurrentView = App.Container.GetInstance<FifthTaskViewModel>();
            });
        }
    }
}
