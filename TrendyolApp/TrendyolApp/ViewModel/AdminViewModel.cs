using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.EntityFrameworkCore;
using Microsoft.Identity.Client;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;
using TrendyolApp.Model;

namespace TrendyolApp.ViewModel
{
    class AdminViewModel : ViewModelBase
    {
        string[] statusArr = new string[4] { "ArrivedAtWarehouse", "Shipped", "CustomsCheck", "AtPostOffice" };

        private ObservableCollection<Orders> _orders;
        public ObservableCollection<Orders> Orders
        {
            get => _orders;
            set
            {
                _orders = value;
                RaisePropertyChanged(nameof(Orders));
            }
        }

        public ICommand ChangeStatusCommand { get; private set; }

        public AdminViewModel()
        {
            LoadOrders();
            ChangeStatusCommand = new RelayCommand<object>(ChangeStatus);
        }

        private void LoadOrders()
        {
            Orders = new ObservableCollection<Orders>();

            using (var context = new TrendyolDbContext())
            {
                var ordersFromDb = context.Orders.Include(o => o.Users).Include(o => o.Product).ToList();
                if (ordersFromDb != null)
                {
                    foreach (var order in ordersFromDb)
                    {
                        Orders.Add(order);
                    }
                }
            }

        }

        void ChangeStatus(object selectedOrder)
        {
            if (selectedOrder is Orders order)
            {
                var currentStatusIndex = Array.IndexOf(statusArr, order.Status);
                var nextStatusIndex = (currentStatusIndex + 1) % statusArr.Length;
                var newStatus = statusArr[nextStatusIndex];

                order.Status = newStatus;

                using (var context = new TrendyolDbContext())
                {
                    context.Orders.Attach(order);
                    context.Entry(order).State = EntityState.Modified;
                    context.SaveChanges();
                }

                LoadOrders();
            }
        }
    }
}
