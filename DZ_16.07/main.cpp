#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int stringToInt(const string& str) {
    // Проверяем на пустую строку
    if (str.empty()) {
        throw invalid_argument("Empty string");
    }

    int result = 0;
    int sign = 1;
    size_t i = 0;

    // Проверяем на знак числа
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    for (; i < str.length(); ++i) {
        char ch = str[i];
        // Проверяем, что символ является цифрой
        if (ch >= '0' && ch <= '9') {
            // Проверяем на переполнение
            if (result > (numeric_limits<int>::max() - (ch - '0')) / 10) {
                throw overflow_error("Overflow");
            }
            result = result * 10 + (ch - '0');
        } else {
            // Если символ не является цифрой, выбрасываем исключение
            throw invalid_argument("Invalid character in string");
        }
    }

    return result * sign;
}



int main() {
    string input;
    cout << "Enter a number in decimal system: ";
    cin >> input;

    try {
        int result = stringToInt(input);
        cout << "Converted integer value: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }





    return 0;
}
