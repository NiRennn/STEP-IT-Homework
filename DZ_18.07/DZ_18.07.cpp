#include <iostream>
using namespace std;

class Car {
public:
    string mark;
    string model;


    Car(const string mark,const string model) : mark(mark), model(model) {}

    virtual void drive() const;
    virtual void parking() const;
    virtual void doWork() const;

};


class Sedan : public Car {
public:


    Sedan(const string mark,const string model) : Car(mark,model) {}

    void drive() const override
    {
        cout << "Sedan " << mark << " " << model << " rides." << endl;
    }

    void parking() const override
    {
        cout << "Sedan " << mark << " " << model << " is parking." << endl;
    }

    void doWork() const override
    {
        cout << "Sedan " << mark << " " << model << " is doing work." << endl;
    }


};

class Bus : public Car {
public:


    Bus(const string mark,const string model) : Car(mark,model) {}

    void drive() const override
    {
        cout << "Bus " << mark << " " << model << " rides." << endl;
    }

    void parking() const override
    {
        cout << "Bus " << mark << " " << model << " is parking." << endl;
    }

    void doWork() const override
    {
        cout << "Bus " << mark << " " << model << " is doing work." << endl;
    }
};


class Truck : public Car {
public:


    Truck(const string mark,const string model) : Car(mark,model) {}

    void drive() const override
    {
        cout << "Truck " << mark << " " << model << " rides." << endl;
    }

    void parking() const override
    {
        cout << "Truck " << mark << " " << model << " is parking." << endl;
    }

    void doWork() const override
    {
        cout << "Truck " << mark << " " << model << " is doing work." << endl;
    }
};

class Sportcar : public Car {
public:


    Sportcar(const string mark,const string model) : Car(mark,model) {}

    void drive() const override
    {
        cout << "Sportcar " << mark << " " << model << " rides." << endl;
    }

    void parking() const override
    {
        cout << "Sportcar " << mark << " " << model << " is parking." << endl;
    }

    void doWork() const override
    {
        cout << "Sportcar " << mark << " " << model << " is doing work." << endl;
    }
};



int main() {


Sedan sedan("Kia", "Rio");
Bus bus("Mercedes", "Sprinter");
Truck truck("Volvo", "FH");
Sportcar sportcar("Bugatti", "Veyron");

sedan.drive();
sedan.parking();
sedan.doWork();
bus.drive();
bus.parking();
bus.doWork();
truck.drive();
truck.parking();
truck.doWork();
sportcar.drive();
sportcar.parking();
sportcar.doWork();


    return 0;
}

