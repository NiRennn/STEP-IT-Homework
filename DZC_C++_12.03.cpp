#include <iostream>
using namespace std;

#pragma region Task1Funk
void difference(int date1[], int date2[])
{
	int day[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum{}, difyear{};

	if (date1[1] > date2[1])
	{
		int n{};
		n = date1[1];
		date1[1] = date2[1];
		date2[1] = n;
	}
	if (date1[2] > date2[2])
	{
		int n{};
		n = date1[2];
		date1[2] = date2[2];
		date2[2] = n;
	}

	if (date1[2] == date2[2])
	{
		for (size_t i = date1[1]; i < date2[1] - 1; i++)
		{
			sum += day[i];
		}
		sum += ((day[date1[1] - 1] - date1[0]) + date2[0]);
		for (size_t i = date1[2]; i < date2[2] + 1; i++)
		{
			if (i % 4 == 0)
				difyear += 1;
		}
		cout << sum;
	}
	else if (date1[2] != date2[2])
	{
		for (size_t i = date1[1]; i < date2[1] - 1; i++)
		{
			sum += day[i];
		}
		sum += ((day[date1[1] - 1] - date1[0]) + date2[0]);
		difyear = (date2[2] - date1[2]) * 365 + sum;
		for (size_t i = date1[2]; i < date2[2] + 1; i++)
		{
			if (i % 4 == 0)
				difyear += 1;
		}
		cout << difyear;
	}
}
#pragma endregion Task1Funk


#pragma region Task2Funk

double task2(int* arr,int length)
{
    double sum{}, count{};
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
        count++;
    }
    cout << sum / count << endl;
    return sum / count;
}

#pragma endregion Task2Funk

#pragma region Task3Funk

int task3(int* arr,int length)
{
    int countOtr{}, countPol{}, countNull{};
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
            countOtr++;
        if (arr[i] > 0)
            countPol++;
        if (arr[i] == 0)
            countNull++;
    }
    cout << "Number of negative: " << countOtr << endl;
    cout << "Number of positive: " << countPol << endl;
    cout << "Number of equal to zero: " << countNull;
    return 0;
}
#pragma endregion Task3Funk




int main() {

#pragma region Task1

    int firstDate[3]{};
	int secondDate[3]{};


    cout << "Enter the day of the first date: ";
    cin >> firstDate[0];
	cout << "Enter the month of the first date: ";
    cin >> firstDate[1];
	cout << "Enter the year of the first date: ";
    cin >> firstDate[2];
	cout << "Enter the day of the second date: ";
    cin >> secondDate[0];
	cout << "Enter the month of the second date: "; cin >> secondDate[1];
	cout << "Enter the year of the second date: "; cin >> secondDate[2];

	difference(firstDate, secondDate);

#pragma endregion Task1

#pragma region Task2

const int length = 10;
int arr[length] = {2, 4 ,3, 7, 9, 11, 5, 7, 3, 6};
task2(arr, length);

#pragma endregion Task2

#pragma region Task3
const int length = 10;
int arr[length] = {5, -12, 0, 33, -3, 45, 9, 0, -2, 22};
task3(arr, length);


#pragma endregion Task3
    return 0;
}
