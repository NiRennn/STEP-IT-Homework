#include "DZ_28.05.h"

void createStudent(Student &s1)
{
    s1.FIO.createName();
    s1.univer.createUniversity();
    s1.tcc.createTelephoneCityCountry();

}

void printInfo(Student s1)
{
    s1.FIO.printFullName();
    s1.univer.printUniversityInfo();
    s1.tcc.printTelephoneCityCountry();
}


int main() {

    bool endprogr = true;
    int choice{};
    Student s1{};


    while(endprogr == true)
    {
        cout << "Enter your choice: " << endl
             << "1. Create student " << endl
             << "2. Print information " << endl
             << "3. Print private " << endl;
        cin >> choice;

        if (choice == 1)
        {
            createStudent(s1);
        }

        else if (choice == 2)
        {
            printInfo(s1);
        }

        else if (choice == 3)
        {
            getDate(s1);
        }

    }


    return 0;
}
