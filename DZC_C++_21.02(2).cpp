#include <iostream>
#include <cmath>
using namespace std;

int main() {

    //task1

    int start{}, i{}, sum{};

    cout << "Enter number of start: " << endl;
    cin >> start;
    i = start;
    for (; i <= 500; i++, start++) {
        sum = sum + start;

    }
    cout << "The sum of the numbers is " << sum << endl;


//    task2

    int num1{}, num2{}, result = 1;

    cout << "Enter first number: " << endl;
    cin >> num1;
    cout << "Enter second number: " << endl;
    cin >> num2;
    for (int i = 0; i < num2; i++) {
        result = result * num1;
    }
    cout << "The number 1 to the power of number 2: " << result;



//    task3

    int start = 1, end = 1000;
    float res = 0;
    float result;
    for (int i = 0; i <= 1000; i++, start++) {
        res += i;
    }
    result = res / 1000;
    cout << result;


//    task4

    int a, result = 1;
    cout << "enter start from 1 to 20 inclusive: ";
    cin >> a;

    if (1 <= a && a <= 20) {
        for (int i = a; i <= 20; i++) {
            result *= i;
        }
        cout << result;
    } else {
        cout << "Wrong diapason!";
    }


//    task5

    int k{};
    cout << "Enter k: " << endl;
    cin >> k;

    for (int i = 1; i < 10; i++) {
        cout << "\n";
        cout << k << "*" << i << "=" << k * i;

    }

    return 0;
}