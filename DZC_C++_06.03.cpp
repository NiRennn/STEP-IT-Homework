 #include <iostream>

int main() {
#pragma region ZADANIE1
const int row = 2;
const int col = 4;
int arr[row][col] = {5, 9, 8, 6, 1, 7, 11, 21};
int sum{}, sredn{};

//vivod massiva
for (int i = 0; i < col; i++)
{
    cout << arr[0][i] << " ";
}
cout << endl;
for (int i = 0; i < col; i++)
{
    cout << arr[1][i] << " ";
}

//summa
for (int i = 0; i < col; i++)
{
    sum += arr[0][i] + arr[1][i];
}

//srednArifmetich

    sredn = sum / (row * col);

//min and max
int max_num = arr[0][0];
int min_num = arr[0][0];

for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
    {
        if (arr[i][j] > max_num)
            max_num = arr[i][j];
        if (arr[i][j] < min_num)
            min_num = arr[i][j];
    }

cout << endl;
cout << "The sum is " << sum << endl;
cout << "Average " << sredn << endl;
cout << "Max number is " << max_num << endl;
cout << "Min number is " << min_num << endl;
#pragma endregion ZADANIE1

#pragma region ZADANIE2
const int row = 3;
const int col = 4;
int arr[row][col] = {3, 5, 6, 7, 12, 1, 1, 1, 0, 7, 12, 1 };
int sum{}, sum_total{};

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        cout << arr[i][j] << "  ";
        sum += arr[i][j];
    }
    cout << "|  " << sum << endl;
    sum = 0;
}

cout << "------------------" << endl;

for (int j = 0; j < col; j++)
{
    for (int i = 0; i < row; i++)
    {
        sum += arr[i][j];
    }
    sum_total += sum;
    cout << sum << " ";
    sum = 0;
}
cout << " |  " << sum_total << endl;

#pragma endregion ZADANIE2

#pragma region ZADANIE3

srand(time(NULL));
const int row1 = 5, col1 = 10, row2 = 5, col2 = 5;
int arr1[row1][col1], arr2[row2][col2];

for (int i = 0; i < row1; i++)
{
    for (int j = 0; j < col1; j++)
    {
        arr1[i][j] = rand() % 50;
        cout << arr1[i][j] <<   " ";
    }
    cout << endl;
}
cout << endl;
for (int i = 0; i < row2; i++)
{
    for (int j = 0; j < col2; j++)
    {
        arr2[i][j] = arr1[i][j * 2] + arr1[i][j * 2 +1];
        cout << arr2[i][j] << " ";
    }
    cout << endl;
}
#pragma endregion ZADANIE3
    return 0;
}
