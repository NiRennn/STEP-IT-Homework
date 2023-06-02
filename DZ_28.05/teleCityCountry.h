
#include <iostream>
using namespace std;



struct teleCityCount
{
    string telephone;
    string city;
    string country;

    teleCityCount() = default;

    teleCityCount(string telephone, string city, string country)
    {
        this->telephone = telephone;
        this->city = city;
        this->country = country;
    }

    void createTelephoneCityCountry();
    void printTelephoneCityCountry() const;
};