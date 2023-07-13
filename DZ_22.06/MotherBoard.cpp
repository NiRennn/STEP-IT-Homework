#include "DZ_22.06.h"


void  Motherboard :: createMotherboard()
{

    cout << "Enter motherboard name: ";
    cin >> this->motherboardName;
    cout << "Enter name of chipset: ";
    cin >> this->chipsetName;
    this->processor->createCPU();
}

void Motherboard :: printMotherboard() const
{
    cout << "Motherboard name: " << motherboardName << endl;
    cout << "Name of chipset: " << chipsetName << endl;

}


