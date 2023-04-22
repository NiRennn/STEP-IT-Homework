#include <iostream>
using namespace std;
#include <string.h>



int main() {

#pragma region Task1

int count;
char* word = new char[20]{};

cout << "Enter count of shifts: ";
cin >> count;
cin.ignore();
cout << "Enter your word: ";
cin.getline(word, 20);

for (int i = 0; i < strlen(word); i++)
{
    if(word[i] > 64 && word[i] < 91)
    {
        if (word[i] <= (90 - count))
            word[i] += count;
        else
            word[i] = word[i] - (26 - count);
    }
    if (word[i] > 96 && word[i] < 123)
    {
        if (word[i] <= (122 - count))
            word[i] += count;
        else
            word[i] = word[i] - (26 - count);
    }

}

cout << word;

#pragma endregion Task1

#pragma region Task2

    int count = 2;
    char* word = new char[20]{};

    cout << "Enter count of shifts: ";
    cin >> count;
    cin.ignore();
    cout << "Enter your word: ";
    cin.getline(word, 20);

    for (int i = 0; i < strlen(word); i++)
    {
        if(word[i] > 64 && word[i] < 91)
        {
            if (word[i] <= (90 - count))
                word[i] += count;
            else
                word[i] = word[i] - (26 - count);
        }
        if (word[i] > 96 && word[i] < 123)
        {
            if (word[i] <= (122 - count))
                word[i] += count;
            else
                word[i] = word[i] - (26 - count);
        }

    }
    cout << word << endl;

int tmp{};
for ( int i = 0; i < strlen(word) / 2; i++ )
{
    tmp = word[i];
    word[i] = word[strlen(word) - 1 - i];
    word[strlen(word) - 1 - i] = tmp;
}

    cout << word;

#pragma endregion Task2

#pragma region Task3

int arr[] = {5, 2, 7, 9, 1, 8, 4};

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
for (int i = 0; i < 7; i++)
{
    for (int j = 0; j < 7 - i; j++)
    {
        int tmp{};
        if (arr[j] > arr[j + 1])
        {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
        }
        tmp == 0;
    }
}

for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
}


int arr[] = {5, 2, 7, 9, 1, 8, 4};

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

int tmp{};

for ( int i = 1; i < 7; i++)
{
    tmp = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > tmp)
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[j] = tmp;
}


for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
}



#pragma endregion Task3



#pragma region Task4

char* arr = new char[26]{'w','r','p','y','o','u','e','a','q','d','s',
                         'g','h','f','t','j','i','k','l','x','z',
                         'c','v','b','n','m'};


    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int tmp{};

    for ( int i = 1; i < 26; i++)
    {
        tmp = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > tmp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }


    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }


#pragma endregion Task4



    return 0;
}
