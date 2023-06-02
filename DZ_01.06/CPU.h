#include <iostream>
using namespace std;



struct CPU {
    public:
    string name{};
    float clockSpeedCPU{};
    float performance{};
    int powerConsumption{};


    CPU() = default;

    CPU(string name, float clockSpeedCPU, float performance, int powerConsumption)
    {
        this->name = name;
        this->clockSpeedCPU = clockSpeedCPU;
        this->performance = performance;
        this->powerConsumption = powerConsumption;
    }

    void createCPU();
    void printCPU() const;
};


