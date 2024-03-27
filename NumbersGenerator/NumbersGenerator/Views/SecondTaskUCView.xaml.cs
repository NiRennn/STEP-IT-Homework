using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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

namespace NumbersGenerator.Views
{

    public partial class SecondTaskUCView : UserControl
    {
        int lowerBound, upperBound;

        private ObservableCollection<int> fibonacciNumbers = new ObservableCollection<int>();


        public SecondTaskUCView()
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

                FibonacciListBox.Items.Clear();

            await GenerateAsync();
        }


        private async Task GenerateAsync()
        {
            await Task.Run(() =>
            {
                int prev = 0, next = 1;
                fibonacciNumbers.Add(prev);
                fibonacciNumbers.Add(next);

                for (int i = 2; i <= upperBound; i++)
                {
                    int temp = prev + next;
                    if (temp <= upperBound)
                    {
                        prev = next;
                        next = temp;
                        Application.Current.Dispatcher.Invoke(() =>
                        {
                            FibonacciListBox.Items.Add(temp);
                        });
                    }
                    else
                    {
                        break;
                    }

                    Thread.Sleep(50);
                }
            });
        }

        public ObservableCollection<int> FibonacciNumbers
        {
            get { return fibonacciNumbers; }
        }
    }
}
