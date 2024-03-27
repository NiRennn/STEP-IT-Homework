using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
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

    public partial class FourthTaskUCView : UserControl
    {
        private int lowerBound;
        private int upperBound;
        private ObservableCollection<int> primeNumbers = new ObservableCollection<int>();
        private ObservableCollection<int> fibonacciNumbers = new ObservableCollection<int>();

        private bool isPrimePaused = false;
        private bool isFibonacciPaused = false;

        private CancellationTokenSource primeCancellationTokenSource;
        private CancellationTokenSource fibonacciCancellationTokenSource;

        public FourthTaskUCView()
        {
            InitializeComponent();
            DataContext = this;
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public ObservableCollection<int> PrimeNumbers
        {
            get { return primeNumbers; }
            set
            {
                primeNumbers = value;
                OnPropertyChanged(nameof(PrimeNumbers));
            }
        }

        public ObservableCollection<int> FibonacciNumbers
        {
            get { return fibonacciNumbers; }
            set
            {
                fibonacciNumbers = value;
                OnPropertyChanged(nameof(FibonacciNumbers));
            }
        }

        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
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

            PrimeNumbers.Clear();
            FibonacciNumbers.Clear();

            primeCancellationTokenSource = new CancellationTokenSource();
            fibonacciCancellationTokenSource = new CancellationTokenSource();

            await Task.WhenAll(
                GeneratePrimesAsync(primeCancellationTokenSource.Token),
                GenerateFibonacciAsync(fibonacciCancellationTokenSource.Token));
        }

        private async Task GeneratePrimesAsync(CancellationToken cancellationToken)
        {
            await Task.Run(async () =>
            {
                for (int i = lowerBound; i <= upperBound; i++)
                {
                    while (isPrimePaused)
                    {
                        await Task.Delay(100);
                    }

                    cancellationToken.ThrowIfCancellationRequested();

                    if (IsPrime(i))
                    {
                        Application.Current.Dispatcher.Invoke(() =>
                        {
                            PrimeNumbers.Add(i);
                        });
                    }
                    await Task.Delay(50);
                }
            });
        }

        private async Task GenerateFibonacciAsync(CancellationToken cancellationToken)
        {
            await Task.Run(() =>
            {
                int prev = 0;
                int next = 1;

                Application.Current.Dispatcher.Invoke(() =>
                {
                    FibonacciNumbers.Add(prev);
                    FibonacciNumbers.Add(next);
                });

                while (true)
                {
                    while (isFibonacciPaused)
                    {
                        Task.Delay(100).Wait();
                    }

                    cancellationToken.ThrowIfCancellationRequested();

                    int temp = prev + next;
                    if (temp <= upperBound)
                    {
                        prev = next;
                        next = temp;
                        Application.Current.Dispatcher.Invoke(() =>
                        {
                            FibonacciNumbers.Add(temp);
                        });
                    }
                    else
                    {
                        break;
                    }

                    Task.Delay(100).Wait();
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

        private void PrimePauseButton_Click(object sender, RoutedEventArgs e)
        {
            isPrimePaused = true;
        }

        private void PrimeContinueButton_Click(object sender, RoutedEventArgs e)
        {
            isPrimePaused = false;
        }

        private void FibonacciPauseButton_Click(object sender, RoutedEventArgs e)
        {
            isFibonacciPaused = true;
        }

        private void FibonacciContinueButton_Click(object sender, RoutedEventArgs e)
        {
            isFibonacciPaused = false;
        }
    }
}
