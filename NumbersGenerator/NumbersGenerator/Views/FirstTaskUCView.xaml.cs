using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
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

namespace NumbersGenerator.Views
{

    public partial class FirstTaskUCView : UserControl
    {
        int lowerBound, upperBound;



        public FirstTaskUCView()
        {
            InitializeComponent();
        }

        private async void GenerateButton_Click(object sender, RoutedEventArgs e)
        {
            if (!int.TryParse(LowerBoundTextBox.Text, out lowerBound))
            {
                MessageBox.Show("Invalid lower bound.");
                return;
            }

            if (!int.TryParse(UpperBoundTextBox.Text, out upperBound))
            {
                MessageBox.Show("Invalid upper bound.");
                return;
            }

            if (lowerBound >= upperBound)
            {
                MessageBox.Show("Lower bound should be less than upper bound.");
                return;
            }

            PrimeNumbersListBox.Items.Clear();


            await GenerateAsync();
        }

        private async Task GenerateAsync()
        {
            await Task.Run(() =>
            {
                for (int i = lowerBound; i <= upperBound; i++)
                {
                    if (IsPrime(i))
                    {
                        Application.Current.Dispatcher.Invoke(() =>
                        {
                            PrimeNumbersListBox.Items.Add(i);
                        });
                    }
                    Thread.Sleep(50);
                }
            });
        }

        private bool IsPrime(int num)
        {
            if (num <= 1) return false;
            if (num == 2 || num == 3) return true;
            if (num % 2 == 0 || num % 3 == 0) return false;

            int sqrt = (int)Math.Sqrt(num) + 1;
            for (int i = 6; i <= sqrt; i += 6)
            {
                if (num % (i - 1) == 0 || num % (i + 1) == 0)
                    return false;
            }

            return true;
        }
    
}
}
