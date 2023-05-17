

#include <iostream>

using namespace std;

void plusMinus(float *&numbers, char *&operators, int &i)
{
    int j{};
    if (operators[i] == '+')numbers[i] = numbers[i] + numbers[i + 1];
        else if (operators[i] == '-')
            numbers[i] = numbers[i] - numbers[i + 1];
    if (numbers[i + 1] != '\0')
        j = i + 1;
    else
        j = i;
    while (numbers[j + 1] != '\0')
    {
        numbers[j] = numbers[j + 1];
        j++;
    }
    j = i;
    while (operators[j] != '\0')
    {
        operators[j] = operators[j + 1];
        j++;
    }
    i--;
}

    void multidivision(float *&numbers, char *&operators, int &i) {
        int j{};
        if (operators[i] == '*')
            numbers[i] = numbers[i] * numbers[i + 1];
        else if (operators[i] == '/')
            numbers[i] = numbers[i] / numbers[i + 1];

        if (numbers[i + 1] != '\0')
            j = i + 1;
        else
            j = i;
        while (numbers[j + 1] != '\0') {
            numbers[j] = numbers[j + 1];
            j++;
        }
        j = i;
        while (operators[j] != '\0') {
            operators[j] = operators[j + 1];
            j++;
        }
        i--;
    }

    char *examination(float *&numbers, char *&operators) {
        bool close = true;
        char *calculator = new char[401]{};
        char *brackets = new char[20]{};
        while (close) {
            numbers = new float[200]{};
            operators = new char[200]{};

            cout << "Enter example: ";
            cin.getline(calculator, 100);

            for (size_t i{}; (int) calculator[i] != (int) '\0'; i++) {
                if (((int) calculator[i] < 48 || (int) calculator[i] > 57) && calculator[i] != ' ' &&
                    ((int) calculator[i] < 40 || (int) calculator[i] > 47))
                    continue;
            }
            close = false;

            for (size_t a = 0, j{}, v{}, z{}; (int) calculator[a] != (int) '\0'; a++) {
                if ((int) calculator[a] > 47 && (int) calculator[a] < 58) {
                    numbers[j] = (int) calculator[a] - (int) '0';
                    while ((int) calculator[a + 1] > 47 && (int) calculator[a + 1] < 58) {
                        numbers[j] *= 10;
                        a++;
                        numbers[j] += (int) calculator[a] - (int) '0';
                    }
                    j++;
                } else if ((int) calculator[a] == '(' && (int) calculator[a + 1] == '-') {
                    a += 2;
                    if ((int) calculator[a] > 47 && (int) calculator[a] < 58) {
                        numbers[j] = (int) calculator[a] - (int) '0';
                        while ((int) calculator[a + 1] > 47 && (int) calculator[a + 1] < 58) {
                            numbers[j] *= 10;
                            a++;
                            numbers[j] += (int) calculator[a] - (int) '0';
                        }
                        numbers[j] *= -1;
                        j++;
                    }
                    if (calculator[a + 1] != ')') {
                        close = true;
                        continue;
                    } else
                        a++;
                } else if ((int) calculator[a] > 39 && (int) calculator[a] < 48) {
                    if (calculator[a] == '(' || calculator[a] == ')') {
                        brackets[z] = calculator[a];
                        z++;
                    } else {
                        operators[v] = calculator[a];
                        v++;
                        brackets[z] = calculator[a];
                        z++;
                    }
                }
            }
            int l1{}, l2{};
            while (numbers[l1] != '\0')
                l1++;
            while (operators[l2] != '\0')
                l2++;

            if (l1 == l2 || l2 > l1) {
                close = true;
                continue;
            }
        }

        for (size_t i = 0; brackets[i] != '\0'; i++) {
            if (brackets[i] == ')') {
                for (size_t j = i - 1; brackets[j] != '('; j--) {
                    if (brackets[j] == '*' || brackets[j] == '/') {
                        int v = j - 1;
                        multidivision(numbers, operators, v);
                        int z = j;
                        for (z; brackets[z] != '\0'; z++)
                            brackets[z] = brackets[z + 1];
                        brackets[z - 1] = '\0';
                        j--;
                    }
                }
                for (int j = i - 1; brackets[j] != '('; j--) {
                    if (brackets[j] == '+' || brackets[j] == '-') {
                        int v = j - 1;
                        plusMinus(numbers, operators, v);
                        int z = j;
                        for (z; brackets[z] != '\0'; z++)
                            brackets[z] = brackets[z + 1];
                        brackets[z - 1] = '\0';
                        j--;
                    }
                    int l = i;
                    for (l; brackets[l] != '\0'; l++)
                        brackets[l] = brackets[l + 1];
                    brackets[l] == '\0';
                    i--;
                }

            }
        }
        return calculator;
    }


    int main()
    {
        bool close = true;
        while (close) {
            char *calculator{};
            float *numbers{};
            char *operators{};

            calculator = examination(numbers, operators);

            for (int i = 0; operators[i] != '\0'; i++) {
                if (operators[i] == '*' || operators[i] == '/')
                    multidivision(numbers, operators, i);
            }

            for (int i = 0; operators[i] != '\0'; i++) {
                if (operators[i] == '+' || operators[i] == '-')
                    plusMinus(numbers, operators, i);
            }

            cout << "Result: " << numbers[0] << endl;

            cout << "Enter 0 to close: ";
            cin >> close;
            cin.ignore();
        }
        return 0;
    }

