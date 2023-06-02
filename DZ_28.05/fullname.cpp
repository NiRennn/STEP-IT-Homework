#include "DZ_28.05.h"

#include <iostream>
using namespace std;


void fullname :: createName()
{

    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Patronymic: ";
    cin >> patronymic;


}


void fullname :: printFullName() const
{
    cout << "Full Name: " << name << " " << surname << " " << patronymic << endl;
}