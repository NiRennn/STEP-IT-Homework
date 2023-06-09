#include "DZ_04.06.h"






void Motherboard :: createMotherboard()
{
    cout << "Enter motherboard name: ";
    cin >> motherboardName;
    cout << "Enter name of chipset: ";
    cin >> chipsetName;

}

void Motherboard :: printMotherboard() const
{
    cout << "Motherboard name: " << motherboardName << endl;
    cout << "Name of chipset: " << chipsetName << endl;

}
