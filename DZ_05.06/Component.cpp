#include "DZ_04.06.h"


 void Component :: createComponent()
 {
    cout << "Enter component make: ";
    cin >> make;
    cout << "Enter component model: ";
    cin >> model;
    cout << "Enter component serial number: ";
    cin >> serialNumber;
 }


void Component :: printComponent() const
{
    cout << "Component make: " << make << endl;
    cout << "Component model: " << model << endl;
    cout << "Component serial number: " << serialNumber << endl;
}
