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

namespace TrendyolApp.View
{

    public partial class SuperAdminUCView : UserControl
    {
        public RelayCommand<User> MakeAdminCommand { get; private set; }

        public SuperAdminUCView()
        {
            InitializeComponent();
            MakeAdminCommand = new RelayCommand<User>(MakeAdmin);
            LoadUsers();
        }
        private void MakeAdmin(User user)
        {
            using (var context = new TrendyolDbContext())
            {
                var userToUpdate = context.Users.FirstOrDefault(u => u.Id == user.Id);

                if (userToUpdate != null)
                {
                    userToUpdate.Position = "Admin";

                    context.SaveChanges();
                    MessageBox.Show("The position has been successfully changed");
                    var borderToRemove = WrapPanel.Children.OfType<Border>()
                         .FirstOrDefault(b => b.DataContext == user);
                    if (borderToRemove != null)
                    {
                        WrapPanel.Children.Remove(borderToRemove);
                    }
                }
                else
                {
                    MessageBox.Show("User not found.");
                }
            }
        }
        private void LoadUsers()
        {
            List<User> users;
            using (var context = new TrendyolDbContext())
            {
                users = context.Users.ToList();
            }

            foreach (User user in users)
            {
                if (user.Position == "User")
                {
                    Border border = new Border();
                    border.BorderBrush = Brushes.Black;
                    border.BorderThickness = new Thickness(1);
                    border.CornerRadius = new CornerRadius(5);
                    border.Margin = new Thickness(5);
                    border.Padding = new Thickness(5);
                    border.Width = 220;
                    border.Height = 180;

                    StackPanel stackPanel = new StackPanel();

                    Image image = new Image();
                    image.Source = new BitmapImage(new Uri("C:\\STEP IT Homework\\TrendyolApp\\TrendyolApp\\ProductsImages\\UserImage.jpg"));
                    image.Width = 70;
                    image.Height = 70;
                    image.Stretch = Stretch.UniformToFill;
                    image.Width = 70;
                    image.Height = 70;
                    stackPanel.Children.Add(image);

                    TextBlock nameTextBlock = new TextBlock();
                    nameTextBlock.FontSize = 20;
                    nameTextBlock.HorizontalAlignment = HorizontalAlignment.Center;
                    nameTextBlock.Text = user.Username;
                    nameTextBlock.FontWeight = FontWeights.Bold;
                    nameTextBlock.Margin = new Thickness(5, 5, 5, 0);
                    stackPanel.Children.Add(nameTextBlock);

                    Button makeAdminButton = new Button();
                    makeAdminButton.Content = "Make Admin";
                    makeAdminButton.Width = 150;
                    makeAdminButton.Height = 40;
                    makeAdminButton.Background = Brushes.Black;
                    makeAdminButton.Foreground = Brushes.White;
                    makeAdminButton.BorderThickness = new Thickness(0);
                    makeAdminButton.Command = MakeAdminCommand;
                    makeAdminButton.CommandParameter = user;
                    stackPanel.Children.Add(makeAdminButton);


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
}
