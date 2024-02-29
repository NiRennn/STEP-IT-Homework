using GalaSoft.MvvmLight.Command;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using TrendyolApp.Model;
using TrendyolApp.ViewModel;


namespace TrendyolApp.View
{

    public partial class ShopUCView : UserControl
    {

        public ShopUCView()
        {
            InitializeComponent();
            LoadProducts();

        }

        private void LoadProducts()
        {
            List<Product> products;
            using (var context = new TrendyolDbContext())
            {
                products = context.Products.ToList();
            }

            foreach (Product product in products)
            {
                Border border = new Border();
                border.BorderBrush = Brushes.Black;
                border.BorderThickness = new Thickness(1);
                border.CornerRadius = new CornerRadius(5);
                border.Margin = new Thickness(5);
                border.Padding = new Thickness(5);
                border.Width = 290;
                border.Height = 290;

                StackPanel stackPanel = new StackPanel();

                Image image = new Image();
                image.Source = new BitmapImage(new Uri(product.ProductImageURL));
                image.Width = 100;
                image.Height = 100;
                image.Stretch = Stretch.UniformToFill;
                image.Width = 150;
                image.Height = 150;
                stackPanel.Children.Add(image);

                TextBlock nameTextBlock = new TextBlock();
                nameTextBlock.Text = product.ProductName;
                nameTextBlock.FontWeight = FontWeights.Bold;
                nameTextBlock.Margin = new Thickness(5, 5, 5, 0);
                stackPanel.Children.Add(nameTextBlock);

                TextBlock priceTextBlock = new TextBlock();
                priceTextBlock.Text = "Price: $" + product.ProductPrice.ToString();
                priceTextBlock.Margin = new Thickness(5, 0, 5, 5);
                stackPanel.Children.Add(priceTextBlock);

                Button buyButton = new Button();
                buyButton.Content = "Buy";
                buyButton.Width = 70;
                buyButton.Height = 50;
                buyButton.Background = Brushes.Black;
                buyButton.Foreground = Brushes.White;
                buyButton.BorderThickness = new Thickness(0);
                buyButton.Command = new RelayCommand(() => { App.Container.GetInstance<ShopViewModel>().BuyProduct(product.Id, product.ProductPrice); });
                stackPanel.Children.Add(buyButton);



                border.Child = stackPanel;

                WrapPanel wrapPanel = (WrapPanel)FindName("WrapPanel");
                if (wrapPanel != null)
                {
                    wrapPanel.Children.Add(border);
                }


            }
        }

    }
}
