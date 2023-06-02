#include "DZ_28.05.h"





void teleCityCount :: createTelephoneCityCountry()
{
    cout << "Enter telephone: ";
    cin >> telephone;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter country: ";
    cin >> country;
}

void teleCityCount ::printTelephoneCityCountry() const
{
    cout << "Telephone: " << telephone << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
}