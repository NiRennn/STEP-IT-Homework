
#include "DZ_01_06.h"



void RAM :: createRAM()
{
    cout << "Enter RAM module type: ";
    cin >> moduleType;
    cout << "Enter RAM form factor: ";
    cin >> formFactor;
    cout << "Enter RAM memory size: ";
    cin >> ramMemory;
    cout << "Enter RAM clock speed: ";
    cin >> clockSpeedRAM;
}
void RAM :: printRAM() const
{
    cout << "RAM module type: " << moduleType << endl;
    cout << "RAM form factor: " << formFactor << endl;
    cout << "RAM memory size: " << ramMemory << endl;
    cout << "RAM clock speed: " << clockSpeedRAM << endl;
}


