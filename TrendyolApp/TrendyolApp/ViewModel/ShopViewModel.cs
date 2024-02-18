using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using TrendyolApp.Model;
using TrendyolApp.Service.Interfaces;

namespace TrendyolApp.ViewModel
{
    public class ShopViewModel : ViewModelBase
    {

        private readonly INavigationService _navigationService;
        private readonly CurrentUser _currentUser;



        TrendyolDbContext _trendyoulDB = new TrendyolDbContext();


        public ShopViewModel(INavigationService navigationService, CurrentUser currentUser)
        {
            _navigationService = navigationService;
            _currentUser = currentUser;


        }



        public void BuyProduct(int productId,double productPrice)
        {
            if (productPrice > _currentUser.Balance)
            {
                MessageBox.Show("Not enough money on balance.");
            }
            else
            {
                _currentUser.Balance -= (float)productPrice;


                var user = _trendyoulDB.Users.FirstOrDefault(u => u.Username == _currentUser.UserName);
                if (user != null)
                {
                    user.Balance = _currentUser.Balance;
                    _trendyoulDB.SaveChanges();
                }

                Orders order = new Orders
                {
                    UserId = _currentUser.Id,
                    ProductId = productId,
                    Status = "Order placed"
                };

                using (var context = new TrendyolDbContext())
                {
                    context.Orders.Add(order);
                    context.SaveChanges();
                }

                MessageBox.Show("Product added to your orders!");
            }
                
        }



    }
}
