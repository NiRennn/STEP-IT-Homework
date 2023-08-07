#include <iostream>
using namespace std;


struct Motherboard {
public:
    string motherboardName;
    string chipsetName;

    Motherboard() = default;

    Motherboard(string motherboardName, string chipsetName)
    {
        this->motherboardName = motherboardName;
        this->chipsetName = chipsetName;

    }

    void createMotherboard();
    void printMotherboard() const;
};



