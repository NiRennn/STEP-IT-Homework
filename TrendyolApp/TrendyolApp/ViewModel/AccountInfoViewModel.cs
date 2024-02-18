using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Messaging;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Model;
using TrendyolApp.Service.Interfaces;

namespace TrendyolApp.ViewModel
{
    class AccountInfoViewModel : ViewModelBase
    {
        private readonly INavigationService navigationService;
        private readonly IDataService _dataService;
        private readonly IMessenger _messenger;
        private readonly CurrentUser _currentUser;



        public AccountInfoViewModel(IMessenger messenger, IDataService dataService, INavigationService navigation,CurrentUser currentUser)
        {
            navigationService = navigation;
            _dataService = dataService;
            _messenger = messenger;
            _currentUser = currentUser;
        }

        public string UserNameInfo => _currentUser.UserName;
        public string EmailInfo => _currentUser.Email;
        public string PositionInfo => _currentUser.Position;


    }
}
