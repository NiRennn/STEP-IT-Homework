#include <iostream>
using namespace std;
int main()
{
//    task2
    int arr[]{ 1, 2, 3, 4, 5};
    for (size_t i = 4; i < 5; i--)
    {
    	cout << *(arr + i) << endl;
    }

//    task3

    int side[5]{};

    for (size_t i = 0; i < 5; i++)
    {
    	cout << "Enter side: ";
    	cin >> side[i];
    }
    cout << side[0] + side[1] + side[2] + side[3] + side[4];

//    task4

    const int length = 12;
    int income{}, arr[length], i = 0, month_max = 0, month_min = 0;
    for (size_t i = 0; i < length; i++)
    {
    	cout << "Enter income in " << ' ' << i + 1 << " month:	";
    	cin >> arr[i];
    }
    int max = arr[i];
    for (size_t i = 0; i < length; i++)
    {

    	if (arr[i] > max)
    	{
    		max = arr[i];
    	}
    }
    int	min = arr[i];
    for (size_t i = 0; i < length; i++)
    {

    	if (arr[i] < min)
    	{
    		min = arr[i];
    	}
    }
    for (size_t i = 0; i < length; i++)
    {
    	month_max += 1;
    	if (arr[i] != max)
    	{
    		continue;
    	}
    	else
    	{
    		break;
    	}
    }
    for (size_t i = 0; i < length; i++)
    {
    	month_min += 1;
    	if (arr[i] != min)
    	{
    		continue;
    	}
    	else
    	{
    		break;
    	}
    }
    cout << "Lowest income in " << month_min << " month. " << endl;
    cout << "Biggest income in " << month_max << " month. ";

    return 0;
}