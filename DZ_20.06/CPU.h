#include <iostream>
using namespace std;


struct CPU {
public:
    string name{};
    float *clockSpeedCPU{};
    float *performance{};
    int *powerConsumption{};


    CPU() = default;

    CPU(string name, float clockSpeedCPU, float performance, int powerConsumption)
    {
        this->name = name;
        this->clockSpeedCPU = new float(clockSpeedCPU);
        this->performance = new float(performance);
        this->powerConsumption = new int(powerConsumption);
    }

    void createCPU();
    void printCPU() const;
};


