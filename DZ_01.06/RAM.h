#include <iostream>
using namespace std;


struct RAM {
public:
    string moduleType{};
    string formFactor{};
    int ramMemory{};
    float clockSpeedRAM{};1


    RAM() = default;

    RAM(string moduleType, string formFactor, int ramMemory, float clockSpeedRam)
    {
        this->moduleType = moduleType;
        this->formFactor = formFactor;
        this->ramMemory = ramMemory;
        this->clockSpeedRAM = clockSpeedRam;
    }


    void createRAM();
    void printRAM() const;
};



