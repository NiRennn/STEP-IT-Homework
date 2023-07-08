#include <iostream>
using namespace std;


struct RAM {
public:
    string moduleType{};
    string formFactor{};
    int ramMemory{};
    float clockSpeedRAM{};


    RAM() = default;

    RAM(string moduleType, string formFactor, int ramMemory, float clockSpeedRam)
    {
        this->moduleType = moduleType;
        this->formFactor = formFactor;
        this->ramMemory = ramMemory;
        this->clockSpeedRAM = clockSpeedRam;
    }

    RAM(const RAM& other)
    {
        this->moduleType = other.moduleType;
        this->formFactor = other.formFactor;
        this->ramMemory = other.ramMemory;
        this->clockSpeedRAM = other.clockSpeedRAM;
    }

    void createRAM();
    void printRAM() const;
};



