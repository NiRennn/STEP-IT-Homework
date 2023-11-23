using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using LiveCharts;
using LiveCharts.Wpf;
using MonefyApp.Messages;
using MonefyApp.Models;
using MonefyApp.Service.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;

namespace MonefyApp.ViewModels
{
    class MainWindowModel : ViewModelBase
    {
        private ViewModelBase _currentView;
        public ViewModelBase CurrentView
        {
            get => _currentView;
            set
            {
                Set(ref _currentView, value);
            }
        }
        private readonly IJsonService _jsonService;

        public MainWindowModel( IMessenger _messenger,IJsonService jsonService)
        {
            CurrentView = App.Container.GetInstance<DiagramViewModel>();

            _messenger.Register<NavigationMessage>(this, message =>
            {
                CurrentView = message.ViewModelType;
            });
        }

        private ViewModelBase _dropDownView;
        public ViewModelBase DropDownView
        {
            get => _dropDownView;
            set
            {
                Set(ref _dropDownView, value);
            }
        }

        public RelayCommand MenuButton
        {
            get => new(() =>
            {
                if (DropDownView == null)
                {
                    DropDownView = App.Container.GetInstance<MenuViewModel>();
                }
                else
                {
                    DropDownView = null;
                }
            });
        }

        public RelayCommand MenuLeftButton
        {
            get => new(() =>
            {
                if (DropDownView == null)
                {
                    DropDownView = App.Container.GetInstance<MenuLeftViewModel>();
                }
                else
                {
                    DropDownView = null;
                }
            });
        }

        public RelayCommand Download
        {
            get => new(() =>
            {
            });
        }

    }
}

