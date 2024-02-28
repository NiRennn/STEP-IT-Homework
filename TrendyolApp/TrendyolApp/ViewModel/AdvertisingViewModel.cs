using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.EntityFrameworkCore.Metadata;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Service.Interfaces;

namespace TrendyolApp.ViewModel
{
    class AdvertisingViewModel : ViewModelBase
    {
        INavigationService navigationService;

        public AdvertisingViewModel(INavigationService navigation)
        {
            navigationService = navigation;
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
