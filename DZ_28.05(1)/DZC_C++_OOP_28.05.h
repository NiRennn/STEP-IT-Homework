#include <iostream>
using namespace std;



class DROBb {
public:
    int numerator{};
    int denominator{};

    DROBb() = default;

    DROBb(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    DROBb addition(DROBb b);
    DROBb subtraction(DROBb b);
    DROBb multiply(DROBb b);
    DROBb division(DROBb b);





};