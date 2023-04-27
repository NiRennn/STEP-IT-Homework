#include <iostream>
using namespace std;

struct Boiler {
    char* Brand = new char[30];
    char* Color = new char[30];
    unsigned int Power{};
    unsigned int Capacity{};
    unsigned int Temperature{};

    void createBoiler(){


        cout << "Enter Brand: ";
        cin.getline(Brand,30);

        cout << "Enter Color: ";
        cin.getline(Color,30);

        cout << "Enter Power: ";
        cin >> Power;

        cout << "Enter Capacity: ";
        cin >> Capacity;

        cout << "Enter Temperature: ";
        cin >> Temperature;


    }

    void printBoiler(){
        cout << "Brand:\t" << Brand << endl
             << "Color:\t" << Color << endl
             << "Power:\t" << Power << endl
             << "Capacity:\t" << Capacity << endl
             << "Temperature:\t" << Temperature << endl;

    }
};






int main() {

    Boiler *boiler = new Boiler{};

    boiler->createBoiler();
    boiler->printBoiler();


    return 0;
}
