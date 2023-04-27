#include <iostream>
using namespace std;


int main()
{
//Task1
int num1, num2, num3;
int count = 0;
for (size_t i = 100; i < 1000; i++)
{
num1 = i / 100;
num2 = (i % 100) / 10;
num3 = i % 10;

if (num1 == num2 || num1 == num3 || num2 == num3)
{
count++;
}
}
cout << count;

//Task2
int num1, num2, num3;
int count = 0;
for (size_t i = 100; i < 1000; i++)
{
num1 = i / 100;
num2 = (i % 100) / 10;
num3 = i % 10;

if (num1 != num2 && num1 != num3 && num2 != num3)
{
count++;
}
}
cout << count
//Task3


//Task4
int num_a{}, num_b{};

cout << "enter number: ";
cin >> num_a;

for (size_t num_b = 2; num_b < num_a; num_b++)
{
if (num_a % (num_b * num_b) == 0 && num_a % (num_b*num_b*num_b))
{
cout << num_b << endl;
}
}
Task 5

int number{}, kubsum = 0;

cout << "Enter number: " << endl;
cin >> number;

for (int i = number; i > 0; i /= 10)
{
	kubsum += i % 10;
}
if (kubsum * kubsum * kubsum == number * number)
{
	cout << "Yes" << endl;
}
else
{
	cout << "No";
}


//Task 6

int number;

cout << "Enter your number: " << endl;
cin >> number;

for (int i = 1; i <= number; i++)
{
	if (number % i == 0)
	{
		cout << i << endl;
	}
}

//Task 7


	int number1{}, number2{}, i = 1;

	cout << "Enter first number: " << endl;
	cin >> number1;
	cout << "Enter second number: " << endl;
	cin >> number2;

	while (i < number1 && i < number2)
	{
		i++;
		if (number1 % i == 0 && number2 % i == 0)
		{
			cout << i << endl;
		}
	}


	return 0;
}