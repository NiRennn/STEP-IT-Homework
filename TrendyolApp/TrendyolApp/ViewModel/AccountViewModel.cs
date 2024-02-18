using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Messages;
using TrendyolApp.Service;
using TrendyolApp.Service.Interfaces;

namespace TrendyolApp.ViewModel
{
    class AccountViewModel : ViewModelBase
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

        private readonly INavigationService navigationService;
        private readonly IDataService _dataService;
        private readonly IMessenger _messenger;

        public AccountViewModel(IMessenger _messenger,INavigationService navigation)
        {

            navigationService = navigation;

            CurrentView = App.Container.GetInstance<RegistrationViewModel>();

            _messenger.Register<NavigationMessage>(this, message =>
            {
                CurrentView = message.ViewModelType;
            });
        }

        public RelayCommand GoToAccountInfo
        {
            get => new(() =>
            {
                navigationService.NavigateTo<AccountInfoViewModel>();
            });
        }      
        
        public RelayCommand GoToAdvertising
        {
            get => new(() =>
            {
                navigationService.NavigateTo<AdvertisingViewModel>();
            });
        }

        public RelayCommand GoToBalance
        {
            get => new(() =>
            {
                navigationService.NavigateTo<BalanceViewModel>();
            });
        }

        public RelayCommand GoToShop
        {
            get => new(() =>
            {
                navigationService.NavigateTo<ShopViewModel>();
            });
        }
        public RelayCommand GoToOrders
        {
            get => new(() =>
            {
                navigationService.NavigateTo<OrdersViewModel>();
            });
        }

    }
}
