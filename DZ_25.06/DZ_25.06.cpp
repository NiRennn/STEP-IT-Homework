
#include <iostream>
#include <string>
using namespace std;

#pragma region Task1Class

class Student {
protected:
    string name;
    string surname;
    int age;
    string university;
    int group;

public:

    Student() = default;

    Student(const string& name, const string& surname, int age, const string& university, int group) : name(name), surname(surname){
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->university = university;
        this->group = group;
    }

    void display_info() {
        cout << "Name: " << this->name << endl;
        cout << "Surname: " << this->surname << endl;
        cout << "Age: " << this->age << endl;
        cout << "University: " << this->university << endl;
        cout << "Group: " << this->group << endl;
    }
};

class Aspirant : public Student {
private:
    string namePhD;

public:
    Aspirant(const string& name,const string& surname, int age, const string& university,int group, const string& namePhD) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->university = university;
        this->group = group;
        this->namePhD = namePhD;
    }

    void display_info() {
        Student::display_info();
        cout << "Research Topic: " << this->namePhD << endl;
    }
};

#pragma endregion Task1Class

#pragma region Task2Class

class Passport
{
protected:
    string name;
    string surname;
    string sex;
    string birthdate;
    string validUntil;
    string serialNumber;

public:

    Passport() = default;

    Passport(const string& name, const string& surname, const string& sex, const string& birthdate,const string& validUntil, const string serialNmber)
    {
        this->name = name;
        this->surname = surname;
        this->sex = sex;
        this->birthdate = birthdate;
        this->validUntil = validUntil;
        this->serialNumber = serialNmber;
    }


    void printInfo()
    {
        cout << "Name: " << this->name << endl;
        cout << "Surname: " << this->surname << endl;
        cout << "Sex: " << this->sex << endl;
        cout << "Birthdate: " << this->birthdate << endl;
        cout << "Valid until: " << this->validUntil << endl;
        cout << "Serial Number: " << this->serialNumber << endl;

    }
};

class ForeignPassport : public Passport
{
private:
    string serialNumberForeign;

public:

    ForeignPassport() = default;


    ForeignPassport(const string& name, const string& surname, const string& sex, const string& birthdate,const string& validUntil, const string serialNmber, const string& serialNumberForeign)
    {
        this->name = name;
        this->surname = surname;
        this->sex = sex;
        this->birthdate = birthdate;
        this->validUntil = validUntil;
        this->serialNumber = serialNmber;

        this->serialNumberForeign = serialNumberForeign;
    }

    void printInfo()
    {
        ForeignPassport::printInfo();
        cout <<"Foreign Serial number: " << this->serialNumberForeign << endl;
    }

};




#pragma endregion Task2Class


#pragma region Task3Class

class Transport
{
public:
    float timeForKm;
    float costForKm;

    Transport() = default;




};

class Car : public Transport
{
public:
    float timeForKm = 2;
    float costForKm = 1;

    void resultCar(int distance)
    {
        float resultTime{};
        float resultCost{};

        resultTime = distance * timeForKm;

        resultCost = distance * costForKm;

        cout << "The car will pass " << distance << " km in " << resultTime << " minutes." << endl;
        cout << "The cost of transportation will be: " << resultCost << " $." << endl;

    }
};

class Bicycle : public Transport
{
public:
    float timeForKm = 5;
    float costForKm = 4;

    void resultBicycle(int distance)
    {
        float resultTime{};
        float resultCost{};

        resultTime = distance * timeForKm;

        resultCost = distance * costForKm;

        cout << "The bicycle will pass " << distance << " km in " << resultTime << " minutes." << endl;
        cout << "The cost of transportation will be: " << resultCost << " $." << endl;

    }
};

class Carriage : public Transport
{
public:
    float timeForKm = 4;
    float costForKm = 2;

    void resultCarriage(int distance)
    {
        float resultTime{};
        float resultCost{};

        resultTime = distance * timeForKm;

        resultCost = distance * costForKm;

        cout << "The carriage will pass " << distance << " km in " << resultTime << " minutes." << endl;
        cout << "The cost of transportation will be: " << resultCost << " $." << endl;

    }
};



#pragma endregion Task3Class


int main() {

#pragma region Task1


    Student student1("Igor", "Kostolomov", 24, "First University",3);
    student1.display_info();

    cout << endl;

    Aspirant aspirant1("Elvin", "Azimov", 21, "Second University",5, "C# Progamming");
    aspirant1.display_info();

#pragma endregion Task1

#pragma region Task2

Passport pass1("Igor", "Kostolomov","Male","06.04.1999", "12.09.2025","123456789");
pass1.printInfo();

cout << endl;

ForeignPassport pass2("Igor", "Kostolomov","Male","06.04.1999", "12.09.2025","123456789","987654321");
pass2.printInfo();





#pragma endregion Task2

#pragma region Task3


Car car;
Bicycle bicycle;
Carriage carriage;
int choice{};
int distance{};


cout << "Choose transport type: " << endl
     << "1.Car" << endl
     << "2.Bicycle" << endl
     << "3.Carriage" << endl;
cin >> choice;

cout << "Enter distance: ";
cin >> distance;

switch(choice)
{
    case 1:
    {
        car.resultCar(distance);
        break;
    }
    case 2:
    {
        bicycle.resultBicycle(distance);
        break;
    }
    case 3:
    {
        carriage.resultCarriage(distance);
        break;
    }
}



#pragma endregion Task3





    return 0;
}

