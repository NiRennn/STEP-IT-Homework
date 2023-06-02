#include <iostream>
using namespace std;


struct UniversityInfo
{
    string universityName;
    string universityCity;
    string universityCountry;


    void createUniversity();
    void printUniversityInfo() const;
};