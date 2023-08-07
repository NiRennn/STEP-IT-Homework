#include "DZC_C++_OOP_28.05.h"
#include <iostream>
using namespace std;


    DROBb DROBb ::addition(DROBb b)
    {
        DROBb result{};

        if (denominator == b.denominator)
        {
            result.numerator = numerator + b.numerator;
            result.denominator = denominator;

            return result;
        }
        else if (denominator != b.denominator)
        {
            result.denominator = denominator * b.denominator;
            result.numerator = numerator * b.denominator + b.numerator * denominator;

            return result;
        }
    }

    DROBb DROBb ::subtraction(DROBb b) {
        DROBb result{};
        if (denominator == b.denominator)
        {
            result.numerator = numerator - b.numerator;
            result.denominator = denominator;

            return result;
        }
        else if (denominator != b.denominator)
        {
            result.denominator = denominator * b.denominator;
            result.numerator = numerator * b.denominator - b.numerator * denominator;

            return result;
        }

    }


    DROBb DROBb ::division(DROBb b) {

        DROBb result{};

        result.numerator = numerator * b.denominator;
        result.denominator = denominator * b.numerator;

        return result;
    }


    DROBb DROBb ::multiply(DROBb b) {

        DROBb result{};

        result.numerator = numerator * b.numerator;
        result.denominator = denominator * b.denominator;

        return result;
    }



