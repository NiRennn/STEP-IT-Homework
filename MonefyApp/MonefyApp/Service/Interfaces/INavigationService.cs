using GalaSoft.MvvmLight;
using MonefyApp.View;
using MonefyApp.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace MonefyApp.Service.Interfaces
{
    public interface INavigationService
    {
        public void NavigateTo<T>() where T : ViewModelBase;
    }
}
