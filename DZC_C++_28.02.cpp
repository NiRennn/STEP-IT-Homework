#include <iostream>
using namespace std;
int main()
{

	//task1

	int arr[10] = { 12, 34, 55, 48, -10, 222, 59, -99, 67, 3 };
	int arr1[5], arr2[5];

	for (int i = 0; i < 5; i++)
	{
		arr1[i] = arr[i];

	}
	for (int i = 5; i < 10; i++)
	{
		arr2[i- 5] = arr[i];
	}

	//task2


	int arr1[5] = { 123, 54, 89, -10, 555 };
	int arr2[5] = { 21, -20, 44, 239, -550 };
	int arr3[5];


	for (int i = 0; i < 5; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}

	//task3


	double expenses[7];
	double srednExpenses, totalExpenses{};
	const char* week[7] = { "Monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday " };

	cout << "Enter your expenses:  " << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << "In " << i + 1 << " day: "; cin >> expenses[i];
	}

	for (int i = 0; i < 7; i++)
	{
		totalExpenses += expenses[i];
	}

	srednExpenses = totalExpenses / 7;

	cout << "Average amount spent: " << srednExpenses << endl;
	cout << "Total amount: " << totalExpenses << endl;

	for (int i = 0; i < 7; i++)
	{
		if (expenses[i] > 100)
		{
			cout << "The amount of expenses exceeded 100 in " << week[i] << " : " << expenses[i] << endl;
		}
	}

	return 0;
}
