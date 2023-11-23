using GalaSoft.MvvmLight.Messaging;
using GalaSoft.MvvmLight;
using MonefyApp.Messages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MonefyApp.Service.Interfaces;

namespace MonefyApp.Service.Classes
{

    class NavigationService : INavigationService
    {
        private readonly IMessenger _messenger;
        public NavigationService(IMessenger messenger)
        {
            _messenger = messenger;
        }
        public void NavigateTo<T>() where T : ViewModelBase
        {
            _messenger.Send(new NavigationMessage()
            {
                ViewModelType = App.Container.GetInstance<T>()
                
            }) ;
        }
    }
}
    

