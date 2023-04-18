#include <iostream>
using namespace std;

#pragma region task1LabaFunk
int task1(int num, int exponent)
{
    if (exponent == 0)
        return 1;
    return num * task1(num, exponent - 1);
}
#pragma endregion task1LabaFunk
#pragma region task2LabaFunk

void task2(int num)
{
    if (num == 0)
        return ;
    cout << '*';
    return task2(num - 1);
}

#pragma endregion task2LabaFunk
#pragma region task3LabaFunk

int task3(int a, int b)
{
    if (a == b)
        return 1;
    return b + task3(a, b - 1);
}
#pragma endregion task3LabaFunk

#pragma region task4LabaFunk
int sum[3]{0, 999, 0};
void task4(int arr[100], int i)
{
    for (int j = i; j < i + 10; j++)
    {
        sum[0] += arr[j];
    }
    if (sum[1] > sum[0])
    {
        sum[1] = sum[0];
        sum[2] = i;
    }
    sum[0] = 0;
    if (i == 90)
    {
        cout << "Minimal index: " << sum[2];
        return;
    }

    return task4( arr, i + 1);
}

#pragma endregion task4LabaFunk

int sum[3]{0, 999, 0};
void task4(int arr[100], int i)
{
    for (int j = i; j < i + 10; j++)
    {
        sum[0] += arr[j];
    }
    if (sum[1] > sum[0])
    {
        sum[1] = sum[0];
        sum[2] = i;
    }
    sum[0] = 0;
    if (i == 90)
    {
        cout << "Minimal index: " << sum[2];
        return;
    }

    return task4( arr, i + 1);
}
#pragma endregion task4LabaFunk
#pragma region task5LabaFunk

int maximum(int* arr)
{
    int max_number = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max_number)
            max_number = arr[i];
    }
return max_number;
}

int maximum(int** arr2, int col, int row)
{
    int max_number = arr2[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr2[i][j] > max_number)
                max_number = arr2[i][j];
        }
    }
    return max_number;
}

int maximum(int first_num, int second_num)
{
    if (first_num == second_num)
    return 0;
    else if (first_num < second_num)
    return second_num;
    else if (first_num > second_num)
    return first_num;

    return 0;
}

int maximum(int first_num,int second_num,int third_num)
{
    int num4 = maximum(first_num,second_num);
    if (num4 < third_num)
        return third_num;
    else
        return maximum(first_num,second_num);
}

#pragma endregion task5LabaFunk

int main() {


#pragma region task1Laba

int res = task1(2, 3);
cout << res << endl;

#pragma endregion task1Laba

#pragma region task2Laba

int num{};
cout << "Enter number of symbols: ";
cin >> num;

task2(num);
#pragma endregion task2Laba

#pragma region task3Laba

int a{}, b{};

cout << "Enter a: "; cin >> a;
cout << "Enter b: "; cin >> b;

task3(a, b);

cout << task3(a, b);

#pragma endregion task3Laba

#pragma region task4Laba

int arr[100]{};
int i = 0;

srand(time(NULL));
for (int i = 0; i < 100; i++)
{
    arr[i] = rand() % 10 + 1;
    cout << arr[i] << ' ';
}

cout << endl;
task4(arr,  i);

#pragma endregion task4Laba

#pragma region task5Laba
cout << "FIRST POINT" << endl;
srand(time(NULL));
const int length = 10;
int* arr = new int[length];
for (int i = 0; i < length; i++)
{
    arr[i] = rand() % 10 + 1;
    cout << arr[i] << " ";
}
cout << endl;
cout << "Maximum number is: " << maximum(arr) << endl;
cout << endl;

cout << "SECOND POINT" << endl;

const int row = 2;
const int col = 6;

int **arr2 = new int*[row];

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        arr2[i][j] = rand() % 10 + 1;
    }
}

for (int i = 0; i < col; i++)
{
    cout << arr2[0][i] << " ";
}
cout << endl;
for (int i = 0; i < col; i++)
{
    cout << arr2[1][i] << " ";
}
cout << endl;
cout <<"Maximum number is: " <<  maximum(arr2, col, row);
cout << endl;


cout << endl;

cout << "THIRD POINT" << endl;
int first_num = 20, second_num = 110;
cout << "Maximum number is: " << maximum(first_num, second_num);
cout << endl;

cout << endl;
cout << "FOURTH POINT" << endl;

int third_num = 3;
cout << "Maximum number is: " << maximum(first_num,second_num,third_num);

#pragma endregion task5Laba
    return 0;
}
