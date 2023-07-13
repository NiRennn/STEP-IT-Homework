#include <iostream>
using namespace std;
#include "CPU.h"


struct Motherboard {
public:
    string motherboardName;
    string chipsetName;
    CPU* processor{};


    Motherboard() = default;

    Motherboard(string motherboardName, string chipsetName, CPU& processor)
    {
        this->motherboardName = motherboardName;
        this->chipsetName = chipsetName;
        this->processor = new CPU(processor);

    }

    Motherboard(const Motherboard& other)
    {
        this->motherboardName = other.motherboardName;
        this->chipsetName = other.chipsetName;
        this->processor = new CPU(*other.processor);
    }

    void createMotherboard();
    void printMotherboard() const;



};



