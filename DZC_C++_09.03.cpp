#include <iostream>
using namespace std;



#pragma region task1Funk
int Task1(int number, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= number;;

        return result;
}
#pragma endregion task1Funk

#pragma region task2Funk

int Task2(int start, int end)
{
    int result{};
    for (int i = start; i <= end; i++)
        result += i;

    return result;
}
#pragma endregion task2Funk

#pragma region task3Funk

int Task3(int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int result = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                result += j;
            }
        }
        if (result == i && result) {
            cout << result << endl;
        }
    }
    return 0;
}



#pragma endregion task3Funk

#pragma region task5Funk

int Task5(int number)
{
    if (number / 100000 + number / 10000 % 10 + number / 1000 % 10 == number / 100 % 10 + number / 10 % 10 + number % 10)
    cout << "Number is lucky!";
    else
        cout << "Number is unlucky!";


    return 0;
}

#pragma endregion task5Funk


int main()
{

#pragma region task1

int number{}, exponent{};
cout << "Enter number: "; cin >> number;
cout << "Enter exponent: "; cin >> exponent;
cout << Task1(number, exponent);

#pragma endregion task1

#pragma region task2

int start{}, end{};

cout << "Enter start: "; cin >> start;
cout << "Enter end: "; cin >> end;
cout << Task2(start, end);

#pragma endregion task2

#pragma region task3

int start{}, end{};

cout << "Enter start: "; cin >> start;
cout << "Enter end: "; cin >> end;
cout << Task3(start, end);

#pragma endregion task3

#pragma region task5

int number{};

cout << "Enter number: "; cin >> number;


Task5(number);


#pragma endregion task5





    return 0;
}