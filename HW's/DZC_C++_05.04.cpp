#include <iostream>
using namespace std;


#pragma region task1

void space(char* str)
{
    int i{};
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            str[i] = '\t';
        i++;

    }
    cout << str << endl;
}

#pragma endregion task1

#pragma region task2

int counter(char* str)
{
    int countLetters{}, countNumbers{}, countSymbols{};
    int i{};
    while(str[i] != '\0') {
        if ((int) str[i] >= 48 && (int) str[i] <= 57)
            countNumbers++;
        else if ((int) str[i] >= 65 && (int) str[i] <= 90)
            countLetters++;
        else if ((int) str[i] >= 97 && (int) str[i] <= 122)
            countLetters++;
        else
            countSymbols++;

        i++;
    }
    cout << "Count of numbers: " << countNumbers << endl;
    cout << "Count of letters: " << countLetters << endl;
    cout << "Count of symbols: " << countSymbols << endl;

    return 0;
}

#pragma endregion task2

#pragma region task3

int countWords(char* str)
{
int i{}, count{};

while(str[i] != '\0')
{
    if (str[i - 1] != ' ' && (str[i] == ' ' || str[i + 1] == '\0'))
        count++;
    i++;

}
cout << count << endl;

    return 0;
}

#pragma endregion task3
#pragma region task4

void palindrome(string str, int len)
{
    int i{};

    while(i < len)
    {
        if(str[i] != str[len])
            cout << "Not palindrome!";
        else
            cout << "Palindrome!";
        i++;
        len--;

    }

}


#pragma endregion task4

int main()
{
#pragma region task1

    char *str = new char[101];
    cout << "Enter your string: ";
    cin.getline(str, 100);

    space(str);

#pragma endregion task1

#pragma region task2

char *str = new char[101];
cout << "Enter your string: ";
cin.getline(str, 100);

counter(str);


#pragma endregion task2

#pragma region task3

char* str = new char[101];

cout << "Enter your string: ";
cin.getline(str, 100);

countWords(str);

#pragma endregion task3
#pragma region task4

    string str = "mamam";
    int len{};

    int k{};
    while(str[k] != '\0')
    {
        len++;
    }

    palindrome(str, len);

#pragma endregion task4


    return 0;
}