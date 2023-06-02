#include "fullname.h"
#include "birthDate.h"
#include "university.h"
#include "teleCityCountry.h"
#include <iostream>
using namespace std;


class Student
{
public:
    fullname FIO; //struct
    birthDate* date{}; //struct
    teleCityCount tcc;
    UniversityInfo univer; //struct


    Student() = default;

    Student(fullname FIO, birthDate date,teleCityCount tcc, UniversityInfo univer)
    {
        this->FIO = FIO;
        *this->date = date;
        this->tcc = tcc;
        this->univer = univer;
    }

    birthDate getDate() const
    {
        return *this->date;
    }



};
