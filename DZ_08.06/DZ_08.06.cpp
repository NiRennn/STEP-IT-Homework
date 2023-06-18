#include <iostream>
using namespace std;

float pi = 3.14;

class Circle {
public:
    int radius;
    int length;


    Circle() = default;

    Circle(int radius, int length)
    {
        this->radius = radius;
        this->length = length;
    }



    Circle& operator += (int number)
    {
        this->radius += number;
        this->length = 2 * pi * this->radius;
        return *this;
    }


    Circle& operator -= (int number)
    {
        this->radius -= number;
        this->length -= 2 * pi * this->radius;
        return *this;
    }

    bool operator == (const Circle &c2) const
    {
        return this->radius == c2.radius;
    }

    bool operator != (const Circle &c2) const
    {
        return this->radius != c2.radius;
    }

    bool operator > (const Circle &c2) const
    {
        return this->length > c2.length;
    }

    bool operator < (const Circle &c2) const
    {
        return this->length < c2.length;
    }
};


class Airplane
{
public:
    string airplaneName;
    int passengerCapacity;

    Airplane() = default;

    Airplane(string airplaneName, int passengerCapacity)
    {
        this->airplaneName = airplaneName;
        this->passengerCapacity = passengerCapacity;
    }


    bool operator == (const Airplane &a2) const
    {
        return this->airplaneName == a2.airplaneName;
    }

    bool operator != (const Airplane &a2) const
    {
        return this->airplaneName != a2.airplaneName;
    }

    bool operator < (const Airplane &a2) const
    {
        return this->passengerCapacity < a2.passengerCapacity;
    }

    bool operator > (const Airplane &a2) const
    {
        return this->passengerCapacity > a2.passengerCapacity;
    }

    void operator++ ()
    {
        this->passengerCapacity += 1;
    }

    void operator-- ()
    {
        this->passengerCapacity -= 1;
    }
};





int main() {

#pragma region Task1
    int number{};

Circle c1(3, 9);
Circle c2(4, 10);

cout << "Checking for equality of two radii(c1 == c2): ";
cout << (c1 == c2) << endl;

cout << "Checking for equality of two lengths(c1 > c2): ";
cout << (c1 > c2) << endl;

cout << "Checking for equality of two lengths(c1 < c2): ";
cout << (c1 < c2) << endl;

#pragma endregion Task1


#pragma region Task2


Airplane a1("Airbus", 150);
Airplane a2("Boeing", 120);


cout << "Checking for equality of two names(a1 == a2): ";
cout << (a1 == a2) << endl;

cout << "Checking for equality of two passangers capacity(a1 > a2): ";
cout << (a1 > a2) << endl;

cout << "Checking for equality of two passangers capacity(a1 < a2): ";
cout << (a1 < a2) << endl;

++a1;
++a2;
cout << "Increase in the number of passengers by 1 of first airplane: ";
cout << a1.passengerCapacity << endl;

cout << "Increase in the number of passengers by 1 of second airplane: ";
cout << a2.passengerCapacity << endl;

--a1;
--a2;

cout << "Increase in the number of passengers by 1 of first airplane: ";
cout << a1.passengerCapacity << endl;

cout << "Increase in the number of passengers by 1 of second airplane: ";
cout << a2.passengerCapacity << endl;


#pragma endregion Task2

    return 0;
}
