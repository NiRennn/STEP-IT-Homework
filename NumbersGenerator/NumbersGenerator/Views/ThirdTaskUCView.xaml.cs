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

    public partial class ThirdTaskUCView : UserControl
    {

        int lowerBound, upperBound;
        private ObservableCollection<int> fibonacciNumbers = new ObservableCollection<int>();
        private CancellationTokenSource primeCancellationTokenSource;
        private CancellationTokenSource fibonacciCancellationTokenSource;

        public ThirdTaskUCView()
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
            FibonacciNumbersListBox.Items.Clear();


            primeCancellationTokenSource = new CancellationTokenSource();
            fibonacciCancellationTokenSource = new CancellationTokenSource();

            Task primeTask = GeneratePrimesAsync();
            Task fibonacciTask = GenerateFibonacciAsync();

            await Task.WhenAll(primeTask, fibonacciTask);
        }

        private async Task GeneratePrimesAsync()
        {
            await Task.Run(() =>
            {
                for (int i = lowerBound; i <= upperBound; i++)
                {
                    if(primeCancellationTokenSource.Token.IsCancellationRequested)
                        return;
                    
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

        private async Task GenerateFibonacciAsync()
        {
            await Task.Run(() =>
            {
                int prev = 0, next = 1;
                fibonacciNumbers.Add(prev);
                fibonacciNumbers.Add(next);


                for (int i = 2; i <= upperBound; i++)
                {
                    if (fibonacciCancellationTokenSource.Token.IsCancellationRequested)
                        return;

                    int temp = prev + next;
                    if (temp <= upperBound)
                    {
                        prev = next;
                        next = temp;
                        Application.Current.Dispatcher.Invoke(() =>
                        {
                            FibonacciNumbersListBox.Items.Add(temp);
                        });
                    }
                    else
                    {
                        break;
                    }

                    Thread.Sleep(100);
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

        private void PrimeStopButton_Click(object sender, RoutedEventArgs e)
        {
            if(primeCancellationTokenSource != null)
            {
                primeCancellationTokenSource.Cancel();
            }
        }

        private void FibonacciStopButton_Click(object sender, RoutedEventArgs e)
        {
            if(fibonacciCancellationTokenSource != null)
            {
                fibonacciCancellationTokenSource.Cancel();
            }
        }


    }


}

