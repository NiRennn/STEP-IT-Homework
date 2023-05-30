#include <iostream>
using namespace std;

void plusMinus(float *&numbers, char *&oper, int &i)
{
    int j{};
    if (oper[i] == '+')numbers[i] = numbers[i] + numbers[i + 1];
    else if (oper[i] == '-')
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
    while (oper[j] != '\0')
    {
        oper[j] = oper[j + 1];
        j++;
    }
    i--;
}

void umnDel(float *&numbers, char *&oper, int &i)
{
    int j{};
    if (oper[i] == '*')
        numbers[i] = numbers[i] * numbers[i + 1];
    else if (oper[i] == '/')
        numbers[i] = numbers[i] / numbers[i + 1];

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
    while (oper[j] != '\0')
    {
        oper[j] = oper[j + 1];
        j++;
    }
    i--;
}

char *otric(float *&numbers, char *&oper)
{
    bool close = true;
    char *calculator = new char[401]{};
    char *skobki = new char[20]{};
    while (close) {
        numbers = new float[200]{};
        oper = new char[200]{};

        cout << "Enter example: ";
        cin.getline(calculator, 100);

        for (size_t i{}; (int) calculator[i] != (int) '\0'; i++)
        {
            if (((int) calculator[i] < 48 || (int) calculator[i] > 57) && calculator[i] != ' ' &&
                ((int) calculator[i] < 40 || (int) calculator[i] > 47))
                continue;
        }
        close = false;

        for (size_t a = 0, j{}, v{}, z{}; (int) calculator[a] != (int) '\0'; a++)
        {
            if ((int) calculator[a] > 47 && (int) calculator[a] < 58) {
                numbers[j] = (int) calculator[a] - (int) '0';
                while ((int) calculator[a + 1] > 47 && (int) calculator[a + 1] < 58)
                {
                    numbers[j] *= 10;
                    a++;
                    numbers[j] += (int) calculator[a] - (int) '0';
                }
                j++;
            } else if ((int) calculator[a] == '(' && (int) calculator[a + 1] == '-')
            {
                a += 2;
                if ((int) calculator[a] > 47 && (int) calculator[a] < 58) {
                    numbers[j] = (int)calculator[a] - (int) '0';
                    while ((int) calculator[a + 1] > 47 && (int) calculator[a + 1] < 58)
                    {
                        numbers[j] *= 10;
                        a++;
                        numbers[j] += (int)calculator[a] - (int) '0';
                    }
                    numbers[j] *= -1;
                    j++;
                }
                if (calculator[a + 1] != ')') {
                    close = true;
                    continue;
                } else
                    a++;
            } else if ((int) calculator[a] > 39 && (int) calculator[a] < 48)
            {
                if (calculator[a] == '(' || calculator[a] == ')')
                {
                    skobki[z] = calculator[a];
                    z++;
                } else {
                    oper[v] = calculator[a];
                    v++;
                    skobki[z] = calculator[a];
                    z++;
                }
            }
        }
        int l1{}, l2{};
        while (numbers[l1] != '\0')
            l1++;
        while (oper[l2] != '\0')
            l2++;

        if (l1 == l2 || l2 > l1)
        {
            close = true;
            continue;
        }
    }

    for (size_t i = 0; skobki[i] != '\0'; i++)
    {
        if (skobki[i] == ')')
        {
            for (size_t j = i - 1; skobki[j] != '('; j--)
            {
                if (skobki[j] == '*' || skobki[j] == '/')
                {
                    int v = j - 1;
                    umnDel(numbers, oper, v);
                    int z = j;
                    for (z; skobki[z] != '\0'; z++)
                        skobki[z] = skobki[z + 1];
                    skobki[z - 1] = '\0';
                    j--;
                }
            }
            for (int j = i - 1; skobki[j] != '('; j--)
            {
                if (skobki[j] == '+' || skobki[j] == '-')
                {
                    int v = j - 1;
                    plusMinus(numbers, oper, v);
                    int z = j;
                    for (z; skobki[z] != '\0'; z++)
                        skobki[z] = skobki[z + 1];
                    skobki[z - 1] = '\0';
                    j--;
                }
                int l = i;
                for (l; skobki[l] != '\0'; l++)
                    skobki[l] = skobki[l + 1];
                skobki[l] == '\0';
                i--;
            }
        }
    }
    return calculator;
}

int main()
{
    float *numbers{};
    char *calc{};
    char *oper{};

    calc = otric(numbers, oper);

    for (int i = 0; oper[i] != '\0'; i++)
    {
        if (oper[i] == '*' || oper[i] == '/')
            umnDel(numbers, oper, i);
    }

    for (int i = 0; oper[i] != '\0'; i++)
    {
        if (oper[i] == '+' || oper[i] == '-')
            plusMinus(numbers, oper, i);
    }

    cout << "Result: " << numbers[0] << endl;

    return 0;
}

