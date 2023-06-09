#include <iostream>
using namespace std;

class Component {
protected:
    string make;
    string model;
    string serialNumber;
public:
    Component(string make, string model, string serialNumber)
    {
        this->make = make;
        this->model = model;
        this->serialNumber = serialNumber;
    }

    void createComponent();
    void printComponent() const;
};


