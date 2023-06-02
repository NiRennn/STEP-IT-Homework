#include <iostream>
using namespace std;

struct fullname
{
    string name;
    string surname;
    string patronymic;


    void createName();
    void printFullName() const;
};