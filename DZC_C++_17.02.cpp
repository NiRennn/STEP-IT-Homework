#include <iostream>
using namespace std;
int main()
{
//	task1

	int minutes{}, hours{};
	int tim1 = time(0);
	int count = 1;
	int num{};
	srand(time(0));
	int randomNumber = ((rand() % 10 + 1) + rand()) % 500;
	cout << randomNumber;
	cout << "Enter your number: ";
	cin >> num;
	while (randomNumber != num)
	{
		if (num < randomNumber)
		{
			cout << "Random is bigger! Try again: ";
			cin >> num;
			count += 1;
		}
		else if (num > randomNumber)
		{
			cout << "Random is lower! Try again: ";
			cin >> num;
			count += 1;
		}

	}
	cout << "You Won,bitch!" << endl;
	cout << "Your count of tries is " << count << endl;
	float seconds = time(0) - tim1;
	minutes = seconds / 60;
	hours = minutes / 60;
	cout << "Your time is: " << hours << " hours " << minutes << " minutes " << seconds << " seconds ";

//	task2

	float azn{}, usd{}, eur{};
	int currency, currency_to;

	cout << "Enter currency to exchange: \n 1.AZN\n 2.USD\n 3.EUR\n ";
	cin >> currency;
	if (currency == 1)
	{
		cout << "Enter the currency to which you want to transfer: \n 1.USD\n 2.EUR\n ";
		cin >> currency_to;
		cout << "Enter the amount to exchange: " << endl;
		cin >> azn;
		switch (currency_to)
		{
		case 1:
			cout << azn << " AZN" << " = " << azn * 0.59 << "USD." << endl;
			break;
		case 2:
			cout << azn << " AZN" << " = " << azn * 0.55 << " EUR." << endl;
			break;
		}
	}
	else if (currency == 2)
	{
		cout << "Enter the currency to which you want to transfer: \n 1.AZN\n 2.EUR\n ";
		cin >> currency_to;
		cout << "Enter the amount to exchange: " << endl;
		cin >> usd;
		switch (currency_to)
		{
		case 1:
			cout << usd << " USD" << " = " << usd * 1.70 << " AZN." << endl;
			break;
		case 2:
			cout << usd << " USD" << " = " << usd * 0.93 << " EUR." << endl;
			break;
		}
	}
	else if (currency == 3)
	{
		cout << "Enter the currency to which you want to transfer: \n 1.AZN\n 2.USD\n ";
		cin >> currency_to;
		cout << "Enter the amount to exchange: " << endl;
		cin >> eur;
		switch (currency_to)
		{
		case 1:
			cout << eur << " EUR" << " = " << eur * 1.82 << " AZN." << endl;
			break;
		case 2:
			cout << eur << " EUR" << " = " << eur * 1.07 << " USD." << endl;
			break;
		}
	}
	return 0;
}

