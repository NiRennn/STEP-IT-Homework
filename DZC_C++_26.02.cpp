#include <iostream>
using namespace std;
#include<random>
int main()
{
//task1
    int min, max;


    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand();
    }
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Max number: " << max << endl;
    cout << "Min number: " << min << endl;

//task2
    int start, end, diapason, sum, tmp;
    int arr[10]{};

    cout << "Enter start: " << endl;
    cin >> start;
    cout << "Enter end: " << endl;
    cin >> end;
    cout << "Enter diapason: " << endl;
    cin >> diapason;

    if (start > end)
    {
        tmp = end;
        end = start;
        start = tmp;
    }

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % (end - start) + start;
    }

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < diapason)
            sum += arr[i];
    }
    cout << "Sum =  " << sum << endl;

//task3
int start{}, end{}, tmp, max{},min{};
int arr[12]{};
for (int i = 0; i < 12; i++)
{
    cout << "Enter income in " << i + 1 << " month: "; cin >> arr[i];
}

cout << "Enter start of diapason: " << endl; cin >> start;
cout << "Enter end of diapason: " << endl; cin >> end;

max = min = start - 1;

for (int i = start; i < end; i++)
{
    if (arr[i] > arr[max])
        max = i;
    if (arr[i] < arr[min])
        min = i;
}
cout << "Max income in " << max + 1 << " month" << " = " << arr[max] << endl;
cout << "Min income in " << min + 1 << " month" << " = " << arr[min] << endl;

//task4
const int n = 10;
int arr[n];
int i, max{}, maximum{}, min{}, minimum{}, sum{}, sum2{}, proizvChetn = 1, proizv = 1;

    for (int i = 0; i <= 10; ++i)
    {
        if (arr[i] < 0)
            sum += arr[1];

        if (arr[1] > max)
        {
            max = arr[i];
            maximum = i;
        }
        if (arr[1] < min)
        {
            min = arr[i];
            minimum = i;
        }

    }

    if (maximum > minimum)
        for (i = minimum; i <= maximum; ++i)
            proizv *= arr[i];
    else if (minimum > maximum)
        for (i = maximum; i <= minimum; i++)
            proizv *= arr[i];

    for (i = 0; i <= 10; i++)
        if (arr[i] % 2 == 0)
            proizvChetn *= arr[i];

    if (minimum < maximum)
    {
        for (i = minimum + 1; i < maximum; i++) {
            sum2 += arr[i];
        }
    }
    else if (minimum > maximum)
    {
        for (i = maximum + 1; i < minimum; i++)
            sum2 += arr[i];
    }

cout << sum << endl;
cout << proizv << endl;
cout << proizvChetn << endl;
cout << sum2 << endl;

    return 0;
}