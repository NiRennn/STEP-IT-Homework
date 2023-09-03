#include <iostream>
#include <string>
#include <stdexcept>

int stringToInt(const std::string& str) {
    try {
        size_t pos;
        int result = std::stoi(str, &pos);

        if (pos != str.length()) {
            throw std::invalid_argument("Строка содержит недопустимые символы");
        }

        return result;
    } catch (const std::out_of_range& e) {
        throw std::overflow_error("Выход за границы диапазона типа int");
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Неверный формат строки");
    }
}

int main() {
    try {
        std::string input;
        std::cout << "Введите строку с числом: ";
        std::cin >> input;

        int result = stringToInt(input);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
