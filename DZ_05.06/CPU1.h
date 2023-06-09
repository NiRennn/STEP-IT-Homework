#include <iostream>
using namespace std;
#include "Component.h"


struct CPU : public Component{
public:
    string name{};
    float clockSpeedCPU{};
    float performance{};
    int powerConsumption{};


    CPU() = default;

    CPU(string make, string model, string serialNumber,string name, float clockSpeedCPU, float performance, int powerConsumption) : Component(make, model,serialNumber)
    {
        this->name = name;
        this->clockSpeedCPU = clockSpeedCPU;
        this->performance = performance;
        this->powerConsumption = powerConsumption;
    }

    void createCPU();
    void printCPU() const;
};


