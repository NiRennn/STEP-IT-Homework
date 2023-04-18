#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


//    task1
int seconds,minutes, hours{};

cout << "Enter seconds: ";
cin >> seconds;

minutes = seconds / 60;
hours = minutes / 60;

cout << seconds << " seconds is equivalent to " << hours << " hours " << (minutes % 60)
<< " minutes " << (seconds % 60) << " seconds.";



//    task2

float number, cent{};
int dollar{};

cout << "Enter number: ";
cin >> number;

dollar = number;
cent = (number - dollar) * 100;

cout <<number << " it is " << dollar << " dollars " << cent << " cents.";





//    task3

int days, Weeks, day{};

cout << "Enter number of days: ";
cin >> days;

Weeks = days / 7;
day = days - (7 * Weeks);
cout << days << "days it is " << Weeks << " weeks and " << day << " days.";



return 0;
}