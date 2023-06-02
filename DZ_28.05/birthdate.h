#include <iostream>
using namespace std;

struct birthDate{
private:
    unsigned int day{};
    unsigned int month{};
    unsigned int year{};
public:
    birthDate(unsigned int day, unsigned int month, unsigned int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void printDate() const
    {
        cout << "Birthdate: " << day << "." << month << "." << year;
    }

    int getDay()
    {
        return this->day;
    }
};

