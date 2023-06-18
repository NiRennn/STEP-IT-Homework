#include <iostream>
using namespace std;


class Student
{
public:
    string name;
    string surname;
    int age;

    Student() = default;

    Student(string name, string surname, int age)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }



    bool operator==(Student const& other) const
    {
        return this->name == other.name && this->surname == other.surname && this->age;
    }

    bool operator != (Student const& other) const
    {
        return !(*this == other);
    }

    bool operator < (Student const& other) const
    {
        return this->age < other.age;
    }

    bool operator > (Student const& other) const
    {
        return this->age > other.age;
    }

    friend ostream& operator << (ostream& os, const Student& other) {
        os << other.name << " " << other.surname << " " << other.age;
        return os;
    }

    friend istream& operator >> (istream& is, Student& other) {
        cout << "Enter name: ";
        is >> other.name;
    }
};

class Classroom
{
    Student s1;
    Student s2;
    Student s3;
    Student s4;
};



int main() {

    Student s1("Igor","Kostolomov",24);
    Student s2("Anver", "Mamedov",18);
    Student s3("Elnur", "Mamedov",20);
    Student s4("Igor", "Kostolomov",24);


    cout << (s1 == s2) << endl;
    cout << (s1 == s4) << endl;
    cout << (s1 < s3) << endl;
    cout << (s1 > s3) << endl;

    cout << s1;
    return 0;
}
