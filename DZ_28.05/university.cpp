#include "DZ_28.05.h"

void UniversityInfo :: createUniversity()
{
    cout << "Name of University: ";
    cin >> universityName;
    cout << "City: ";
    cin >> universityCity;
    cout << "Country: ";
    cin >> universityCountry;
}

void UniversityInfo :: printUniversityInfo() const
{
    cout << "Name of University: " << universityName << endl
         << "City: " << universityCity << endl
         << "Country: " << universityCountry << endl;
}