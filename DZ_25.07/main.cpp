#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <exception>


class Transport
{
    public:
    virtual ~Transport() {}

    virtual void print() const;

    bool operator==(const Transport& other) const
    {
        return this->toString() == other.toString();
    }

    bool operator!=(const Transport& other) const
    {
        return !(*this == other);
    }

    friend std :: ostream& operator<<(std:: ostream& os, const Transport& transport){
        os << transport.toString();
        return os;
        }

        friend std :: ostream operator<<(std:: ostream& os, const Transport transport){
        os << transport.toString();
    }

    virtual std :: string toString() const;
};



class Car : public Transport
{
private:
    std :: string mark;
public:

    Car(const std :: string& mark) : mark(mark) { }

    void print() const override {
        std :: cout << "Car mark: " << mark;
    }
};

std :: regex carR("Car mark: (.+)");

class Plane : public Transport
{
private:
    std :: string mark;
public:

    Plane(const std :: string& mark) : mark(mark) { }

    void print() const override {
        std :: cout << "Plane mark: " << mark;
    }
};

std :: regex planeR("Plane mark: (.+)");


class Boat : public Transport
{
private:
    std :: string mark;
public:

    Boat(const std :: string& mark) : mark(mark) { }

    void print() const override {
        std :: cout << "Plane mark: " << mark;
    }
};

std :: regex boatR("Boat mark: (.+)");

class Exception : public std :: exception
{
private:
    std :: string result;

public:
    Exception(std::string& msg) : result(msg) {}

    const char* what() const noexcept override {
        return result.c_str();
    }

};
class ComparisonException : public std::exception {
private:
        std :: string result;
public:
        ComparisonException(std::string& msg) : result(msg) {}

            const char* what() const noexcept override {
                return result.c_str();
            }


    };


void writeException(std::exception& excep) {
    std :: ofstream outFile("exception.csv", std::ios::app);

    if (outFile.is_open()) {
        outFile << excep.what() << "\n";
        outFile.close();
    }
    else {
        throw Exception("Error opening file for writing. ");
    }
}


int main() {


    try {
        Transport *car = new Car("Mercedes");
        Transport *plane = new Plane("Boeing");
        Transport *boat = new Boat("Arctic boat");

        try {

        }

    }



    return 0;
}
