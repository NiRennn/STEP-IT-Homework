#include "DZC_C++_OOP_28.05.h"


void createDrob(int &numerator, int &denominator)
{
    int tmp{};
    cout << "Enter Numerator: "; cin >> numerator;
    cout << "Enter Denominator: "; cin >> tmp;
    while (tmp == 0)
    {
        cout << "Denominator can't be 0 ! Re-enter denominator: ";
        cin >> tmp;

    }
    denominator = tmp;
}

void printResult(DROBb result)
{
    cout << "Result: " <<  result.numerator << '/' << result.denominator << endl;
}

int main() {

int numerator{};
int denominator{};
int choice{};

bool endprogr = true;



while(endprogr = true)
{
    cout << "First fraction: ";
    createDrob(numerator, denominator);
    DROBb drob1(numerator, denominator);

    cout << "Second fraction: ";
    createDrob(numerator, denominator);
    DROBb drob2(numerator, denominator);

    cout << "Enter your choice: " << endl
         << "1. Addition " << endl
         << "2. Subtraction" << endl
         << "3. Division " << endl
         << "4. Multiplication " << endl
         << "5. End program " << endl;
    cin >> choice;


    if (choice == 1)
    {
        DROBb drob3 = drob1.addition(drob2);
        printResult(drob3);

    }
    else if (choice == 2)
    {
        DROBb drob3 = drob1.subtraction(drob2);
        printResult(drob3);

    }
    else if (choice == 3)
    {
        DROBb drob3 = drob1.division(drob2);
        printResult(drob3);

    }
    else if (choice == 4)
    {
        DROBb drob3 = drob1.multiply(drob2);
        printResult(drob3);

    }

}




    return 0;
}
