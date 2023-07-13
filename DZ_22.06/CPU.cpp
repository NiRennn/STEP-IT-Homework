#include "CPU.h"



void CPU :: createCPU()
{
    cout << "Enter name of CPU: ";
    cin >> name;
    cout << "Enter clock speed of CPU: ";
    cin >> *clockSpeedCPU;
    cout << "Enter CPU performance: ";
    cin >> *performance;
    cout << "Enter power consumption of CPU: ";
    cin >> *powerConsumption;
}
void CPU :: printCPU() const
{
    cout << "Name of CPU: " << name << endl;
    cout << "Clock speed of CPU: " << *clockSpeedCPU << endl;
    cout << "CPU performance: " << *performance << endl;
    cout << "Power consumption of CPU: " << *powerConsumption << endl;
}


