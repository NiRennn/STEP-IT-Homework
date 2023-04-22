#include <iostream>
using namespace std;
#include <random>
#include <stdlib.h>


#pragma region func1
void minMax(int* arr, int length)
{
    int min = arr[0], max = arr[0], minIndex{}, maxIndex{};
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    for (size_t i = 0; i < length; i++, maxIndex++)
    {
        if (arr[i] == max)
            break;
    }
    for (size_t i = 0; i < length; i++, minIndex++)
    {
        if (arr[i] == min)
            break;
    }
    cout << "Maximmum number is " << max << ". Index is " << maxIndex << endl;
    cout << "Minimmum number is " << min << ". Index is " << minIndex;
}
#pragma endregion func1

#pragma region func2
void poryadok(int length, int* arr,int* arr2)
{
    for (int i = 0; i < length; i++)
        arr2[i] = arr[i];

    for (int i = 0; i < length; i++) {
        arr[i] = arr2[length - 1 - i];
    }

}


#pragma endregion func2

#pragma region func3
void isPrime(int length,int* arr)
{
    int count{}, count2{};

    for (int i = 0; i <= length; i++)
    {
        count2 = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                count2++;
            }
        }
        if (count2 == 2)
        {
            cout << arr[i] << endl;
            count++;
        }

    }
    cout << "Count is " << count << endl;

}
#pragma endregion func3

int main()
{


#pragma region Task1

    {
        int length{}, minIndex{}, maxIndex{};
        int* arr = (int*) calloc(length, length * sizeof(int));
        int* arr2 = (int*)calloc(length, length * sizeof(int));
        cout << "enter length:"; cin >> length;
        for (size_t i = 0; i < length; i++)
        {
            cout << "enter " << i + 1 << " number: ";
            cin >> arr[i];
        }
        minMax(arr, length);
    }

#pragma endregion Task1

#pragma region Task2

int length{};
cout << "Enter length of array: ";
cin >> length;

int *arr = new int[length];
int *arr2 = new int[length]{};

for (int i = 0; i < length; i++)
srand(time(NULL));

for (int i = 0; i < length; i++)
{
arr[i] = rand() % 10;
}
for (int i = 0; i < length; i++)
{
    cout << arr[i] << " ";
}
cout << endl;
poryadok(length,arr,arr2);
for (int i = 0; i < length; i++)
    cout << arr[i] << " ";

#pragma endregion Task2

#pragma region Task3

int length{};
cout << "Enter length of array: ";
cin >> length;

int *arr = new int[length];

for (int i = 0; i < length; i++)
{
    cout << "Enter element: ";
    cin >> arr[i];
}

for (int i = 0; i < length; i++)
    cout << arr[i] << " ";

isPrime(length,arr);

#pragma endregion Task3




    return 0;
}