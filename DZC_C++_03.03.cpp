#include <iostream>
using namespace std;

#pragma region Task1
void rectangle(int N, int K)
{
    cout << "Enter length of rectangle: "; cin >> K;
    cout << "Enter width of rectangle: "; cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}
#pragma endregion Task1

#pragma region Task2
void factorial(int number)
{
    int fact = 1;
    cout << "Enter number of factors: "; cin >> number;
    for (int i = 1; i < number + 1; i++)
    {
        fact *= i;
    }
    cout << fact;
}
#pragma endregion Task2

#pragma region Task3

void checkNumber(int number)
{
    int count{};
    cout << "Enter number: "; cin >> number;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            count++;

    }
        if (count > 1)
        {
            cout << "Your number is not prime!";
        }
        else
        {
            cout << "Your number is prime!";
        }
}
#pragma endregion Task3

#pragma region Task4

void cubeNumber(int number)
{
//first option

    cout << "Enter the number to cube: "; cin >> number;
    cout << number << " to the power of 3 is : " << number * number * number;

//second option
    int power = 4;
    int answer = 1;
    cout << "Enter the number to cube: "; cin >> number;
    for (int i = 0; i < power; i++)
    {
        answer *= number;
    }
    cout << number << " to the power of 3 is : " << answer;

}





#pragma endregion Task4

#pragma region Task5

void lowerBigger(float number1,float number2)
{
    cout << "Enter first number: "; cin >> number1;
    cout << "Enter second number: "; cin >> number2;
    if  (number1 > number2)
        cout << "First number is greater than second!";
    else if (number1 < number2)
        cout << "Second number is greater than first!";
    else
        cout << "The numbers are equal!";

}
#pragma endregion Task5

#pragma region Task6

void lastTask(int number)
{
cout << "Enter number: "; cin >> number;
    if (number > 0)
        cout << "True";
    else if (number < 0)
        cout << "False";
    else
        cout << "You entered zero!";

}
#pragma endregion Task6

int main()
{

rectangle(4,7);
factorial(5)
checkNumber(5);
cubeNumber( 5);
lowerBigger(5,7);
lastTask(5);

    return 0;
}