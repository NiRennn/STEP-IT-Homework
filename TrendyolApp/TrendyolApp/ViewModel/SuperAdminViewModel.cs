using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using Microsoft.EntityFrameworkCore.Metadata;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Model;
using TrendyolApp.Service.Interfaces;
using TrendyolApp.View;

namespace TrendyolApp.ViewModel
{
    class SuperAdminViewModel : ViewModelBase
    {
        private readonly INavigationService navigationService;
        private readonly IDataService _dataService;
        private readonly IMessenger _messenger;
        private CurrentUser _currentUser;

        TrendyolDbContext _trendyoulDB = new TrendyolDbContext();
        public SuperAdminViewModel(IMessenger messenger,IDataService dataService)
        {
            _dataService = dataService;
            _messenger = messenger;
        }


       
    }
}
