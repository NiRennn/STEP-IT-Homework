#include <iostream>
using namespace std;

int main() {


#pragma region Task1

int num;
const int row = 2;
const int col = 5;
int arr[row][col]{};

cout << "Enter number: "; cin >> num;

arr[0][0] = num;
for (int i = 0; i < col; i++)
{

    num = arr[0][i + 1] = num * 2;
}

for (int i = 0; i < col; i++)
{
    num = arr[1][i + 1] = num * 2;
}

for (int i = 0; i < col; i++)
{
    cout << arr[0][i] << " ";
}
cout << "\n";
for (int i = 0; i < col; i++)
{
    cout << arr[1][i] << " ";
}

#pragma endregion Task1

#pragma region Task2


const int row = 2;
const int col = 5;
int arr[row][col]{};
int num{};

cout << "Enter number: "; cin >> num;
arr[0][0] = num;

for (int i = 0; i < col; i++)
{
    num = arr[0][i + 1] = num + 1;
}
for (int i = 0; i < col; i++)
{
    num = arr[1][i + 1] = num + 1;
}
for (int i = 0; i < col; i++)
{
    cout << arr[0][i] << " " ;
}
    cout << "\n";
for (int i = 0; i < col; i++)
{
    cout << arr[1][i] << " ";
}

#pragma endregion Task2


#pragma region Task3

int const row = 3, col = 6;
int arr[row][col], arr2[row][col];
int shift{}, count{};
int j{};

srand(time(NULL));
for (int i = 0; i < 6; i++)
{
    arr[0][i] = rand() % 10;
    arr[1][i] = rand() % 10;
    arr[2][i] = rand() % 10;

}

for (int i = 0; i < col; i++)
{
    cout << arr[0][i] << " ";
}
    cout << "\n";
for (int i = 0; i < col; i++)
{
    cout << arr[1][i] << " ";
}
    cout << "\n";
for (int i = 0; i < col; i++)
{
    cout << arr[2][i] << " ";
}
cout << "\nChoose direction to shift:\n "
        "1. Right\n"
        " 2. Left\n"
        " 3. Down\n"
        " 4. Up \n";
cin >> shift;


switch(shift)
{
    case 1:
        cout << "Enter count of shifts: "; cin >> count;
        count = count % col;
        for (int i = 0; i < count; i++)
        {
            arr2[0][i] = arr[0][i + col - count];
            arr2[1][i] = arr[1][i + col - count];
            arr2[2][i] = arr[2][i + col - count];
            j++;
        }
        for (int i = j; i < col; i++)
        {
            arr2[0][i] = arr[0][i - j];
            arr2[1][i] = arr[1][i - j];
            arr2[2][i] = arr[2][i - j];
        }

        break;
    case 2:
        cout << "Enter count of shifts: "; cin >> count;
        count = count % col;
        for (int i = 0; i < count; i++)
        {
            arr2[0][i] = arr[0][i + count];
            arr2[1][i] = arr[1][i + count];
            arr2[2][i] = arr[2][i + count];
            j++;
        }
        for (int i = j; i < col; i++)
        {
            arr2[0][i] = arr[0][i - j];
            arr2[1][i] = arr[1][i - j];
            arr2[2][i] = arr[2][i - j];
        }
        break;
    case 3:
        cout << "Enter count of shifts: "; cin >> count;
        count = count % row;
        for (int i = 0; i < count; i++)
        {
            arr2[i][0] = arr[i + row - count] [0];
            arr2[i][1] = arr[i + row - count] [1];
            arr2[i][2] = arr[i + row - count] [2];
            arr2[i][3] = arr[i + row - count] [3];
            arr2[i][4] = arr[i + row - count] [4];
            arr2[i][5] = arr[i + row - count] [5];
            j++;
        }
        for (int i = j; i < row; i++)
        {
            arr2[i][0] = arr[i - j] [0];
            arr2[i][1] = arr[i - j] [1];
            arr2[i][2] = arr[i - j] [2];
            arr2[i][3] = arr[i - j] [3];
            arr2[i][4] = arr[i - j] [4];
            arr2[i][5] = arr[i - j] [5];
        }
        break;
    case 4:
        cout << "Enter count of shifts: "; cin >> count;
        count %= row;
        for (int i = 0; i < count; i++)
        {
            arr2[i][0] = arr[i + count] [0];
            arr2[i][1] = arr[i + count] [1];
            arr2[i][2] = arr[i + count] [2];
            arr2[i][3] = arr[i + count] [3];
            arr2[i][4] = arr[i + count] [4];
            arr2[i][5] = arr[i + count] [5];
            j++;
        }
        for (int i = j; i < row; i++)
        {
            arr2[i][0] = arr[i - j] [0];
            arr2[i][1] = arr[i - j] [1];
            arr2[i][2] = arr[i - j] [2];
            arr2[i][3] = arr[i - j] [3];
            arr2[i][4] = arr[i - j] [4];
            arr2[i][5] = arr[i - j] [5];
        }
        break;
}

for (int i = 0; i < 6; i++)
{
    cout << arr2[0][i] << " ";
}
cout << "\n";
for (int i = 0; i < 6; i++)
{
    cout << arr2[1][i] << " ";
}
cout << "\n";
for (int i = 0; i < 6; i++)
{
    cout << arr2[2][i] << " ";
}

#pragma endregion Task3
}
