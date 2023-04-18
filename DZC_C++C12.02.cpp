#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    //task1

float R1, R2, R3, R0{};

cout << "Enter R1: ";
cin >> R1;
cout << "Enter R12: ";
cin >> R2;
cout << "Enter R13: ";
cin >> R3;
R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
cout << "Resistance value R0: " << R0;

return 0;



    //task2

float R, S, L{};
double pi{};
pi = 3.14;
cout << "Enter circumference: ";
cin >> L;
S = pi * (L / (2 * pi)) * (L / (2 * pi));
cout << "Area of circle​​: " << S;

return 0;


    //task3

	float V, t, a, S{};

cout << "Enter speed (km/h): ";
cin >> V;
cout << "Enter time (h): ";
cin >> t;
cout << "Enter Acceleration (km/h^2): ";
cin >> a;

S = V * t + (a * t * t) / 2;

cout << "Distance traveled: " << S;

return 0;


}