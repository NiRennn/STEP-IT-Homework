using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Views;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Model;
using TrendyolApp.Service.Interfaces;


namespace TrendyolApp.ViewModel
{
    public class OrdersViewModel : ViewModelBase
    {

        public ObservableCollection<Orders> Orders { get; set; }
        private readonly Service.Interfaces.INavigationService navigationService;
        private readonly CurrentUser currentUser;

        public OrdersViewModel(Service.Interfaces.INavigationService navigation,CurrentUser user)
        {
            navigationService = navigation;
            currentUser = user;

        }



        public void LoadOrders()
        {
            

            using (var context = new TrendyolDbContext())
            {
                Orders = new ObservableCollection<Orders>(context.Orders.Include(o => o.Product).Where(o => o.UserId == currentUser.Id));
            }

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
