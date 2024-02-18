using GalaSoft.MvvmLight;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrendyolApp.Model;

namespace TrendyolApp.ViewModel
{
    public class OrdersViewModel : ViewModelBase
    {
        public ObservableCollection<Orders> Orders { get; set; }

        public OrdersViewModel()
        {
            LoadOrders();
        }

        private void LoadOrders()
        {
            Orders = new ObservableCollection<Orders>();

            using (var context = new TrendyolDbContext())
            {
                var ordersFromDb = context.Orders.Include(o => o.Product).ToList();

                foreach (var order in ordersFromDb)
                {
                    Orders.Add(order);
                }
            }
        }
    }
}
