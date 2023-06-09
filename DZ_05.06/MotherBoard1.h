#include <iostream>
using namespace std;
#include "Component.h"


class Motherboard : public Component {
public:
    string motherboardName;
    string chipsetName;

    Motherboard() = default;

    Motherboard(string make, string model, string serialNumber, string motherboardName, string chipsetName) : Component(make,model,serialNumber)
    {
        this->motherboardName = motherboardName;
        this->chipsetName = chipsetName;

    }

    void createMotherboard();
    void printMotherboard() const;
};



