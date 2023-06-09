#include <iostream>
using namespace std;
#include "Component.h"

class RAM : public Component{
public:
    string moduleType{};
    string formFactor{};
    int ramMemory{};
    float clockSpeedRAM{};


    RAM() = default;

    RAM(string make, string model, string serialNumber, string moduleType, string formFactor, int ramMemory, float clockSpeedRam) : Component(make, model, serialNumber)
    {
        this->moduleType = moduleType;
        this->formFactor = formFactor;
        this->ramMemory = ramMemory;
        this->clockSpeedRAM = clockSpeedRam;
    }


    void createRAM();
    void printRAM() const;
};



