#include <iostream>
#include <string.h>
using namespace std;


#pragma region Task1Funk
int Task1(int *arr, int length, int summary = 0, int multiple = 1)
{
    for (int i = 0; i < length; i++)
    {
        summary += arr[i];
    }
    cout << summary << endl;
    for (int i = 0; i < length; i++)
    {
        multiple *= arr[i];
    }
    cout << multiple << endl;

return 0;
}

#pragma endregion Task1Funk

#pragma region Task2Funk

int Task2(int *arr, int length)
{
    int negative{}, positive{}, null;
for (int i = 0; i < length; i++)
{
    if (arr[i] < 0)
        negative++;
    if (arr[i] > 0)
        positive++;
    if (arr[i] == 0)
        null++;

}
    cout << "Count of negative: " << negative << endl;
    cout << "Count of positive: " << positive << endl;
    cout << "Count of equal zero: " << null << endl;

    return 0;
}

#pragma endregion Task2Funk

#pragma region Task3Funk

void Task3Funk(int *arr1, int *arr2, int length1, int length2)
{
    int count = 0;
    for (int i = 0; i < length1; i++)
    {
        int index = i;
        for (int j = 0; j < length2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count++;
            }
            else
                continue;
            if (count == length2)
                cout <<  &arr1[index - length2 + 1];
            break;
        }
    }
}




#pragma endregion Task3Funk

#pragma region Task4Funk

void Task4Funk(int *arr, int length)
{
    int count{};

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
            count++;


    }
    int *arrNew = new int[length - count];
    for (int i = 0, b = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            arrNew[b] = arr[i];
            b++;
        }
    }
    for (int i = 0; i < length - count; i++)
    {
        cout << arrNew[i] << " ";
    }
}

#pragma endregion Task4Funk

#pragma region Task5Funk

void Task5Funk(int *arr, int length,int number)
{
    length++;
    int *arrNew = new int[length - 2]{};

    for (int i = 0; i < length - 1; i++)
    {
        arrNew[i] = arr[i];
    }

    arrNew[length - 1] = number;

    for (int i = 0; i < length; i++)
    {
        cout << arrNew[i] << " ";
    }


}


#pragma endregion Task5Funk

#pragma region Task6Funk

void Task6Funk(int *arr, int length,int number, int index)
{
    length++;
    int *arrNew = new int[length - 2]{};

    for (int i = 0; i < index; i++)
    {
        arrNew[i] = arr[i];
    }

    arrNew[index] = number;

    for (int i = index  ; i < length + 1; i++)
    {
        arrNew[i + 1] = arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        cout << arrNew[i] << " ";
    }
    cout << endl;

}
#pragma endregion Task6Funk

#pragma region Task7Funk

void Task7Funk(int *arr, int length, int index)
{
    int *arrNew = new int[length - 1]{};

    for (int i = 0; i < index; i++)
    {
        arrNew[i] = arr[i];
    }

    for (int i = index  ; i < length + 1; i++)
    {
        arrNew[i] = arr[i + 1];
    }

    length--;

    for (int i = 0; i < length; i++)
    {
        cout << arrNew[i] << " ";
    }
    cout << endl;

}
#pragma endregion Task7Funk



int main() {

#pragma region Task1

int summary{}, multiple = 1;
const int length = 7;
int arr[length];

srand(time(NULL));
for (int i = 0; i < length; i++)
{
    arr[i] = rand() % 9 + 1;
    cout << arr[i] << " ";
}
cout << endl;

Task1(arr, length, summary, multiple);

#pragma endregion Task1

#pragma region Task2

int negative{}, positive{}, null{};
const int length = 10;
int arr[length] = {22, -15, 0, 33, -3, 6, 0, -19, 99, 56};
int *ptrnegative = &negative;
int *ptrpositive = &positive;
int *ptrnull = &null;

for (int i = 0; i < length; i++)
{
    cout << arr[i] << " ";
}
cout << endl;
Task2(arr, length);

#pragma endregion Task2

#pragma region Task3

int length1 = 10, length2 = 3;

int *arr1 = new int[length1]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *arr2 = new int[length2]{5, 6, 7};

cout << &arr1[4];
Task3Funk(arr1, arr2, length1, length2);


#pragma endregion Task3

#pragma region Task4


int length = 10;
int* arr = new int[length]{20, -10, 44, 86, -5, 33, -6, 85, -23, 65};


Task4Funk(arr, length);

#pragma endregion Task4

#pragma region Task5
int number;
int length = 5;
int *arr = new int[length]{12, 44, 55,85, 34};

for (int i = 0; i < length; i++)
{
    cout << arr[i] << " ";
}
cout << endl;

cout << "Enter number to add in array: ";
cin >> number;

Task5Funk(arr, length, number);




#pragma endregion Task5

#pragma region Task6


int index;
int number;
int length = 8;
int *arr = new int[length]{12, 44, 55,85, 34, 55, 98, 23};

for (int i = 0; i < length; i++)
{
    cout << arr[i] << " ";
}
cout << endl;

cout << "Enter number to add in array: ";
cin >> number;

cout << "Enter index: ";
cin >> index;

Task6Funk(arr, length, number, index);

#pragma endregion Task6

#pragma region Task7

int index;
int length = 8;
int *arr = new int[length]{12, 44, 55,85, 34, 55, 98, 23};

for (int i = 0; i < length; i++)
{
    cout << arr[i] << " ";
}
cout << endl;

cout << "Enter index: ";
cin >> index;

Task7Funk(arr, length, index);

#pragma endregion Task7

    return 0;
}
