#include <iostream>
using namespace std;


#pragma region FunkCalculator

void pluss(int *arrNums,char *arrOper, int i)
{
    arrNums[i] = arrNums[i] + arrNums[i + 1];
    int j{};
    if (arrNums[i + 1] != '\0')
        j = i + 1;
    else
        j = i;
    while(arrNums[j + 1] != '\0')
    {
        arrNums[j] = arrNums[j + 1];
        j++;
    }
    arrNums[j] = '\0';
    j = i;
    while(arrOper[j] != '\0')
    {
        arrOper[j] = arrOper[j + 1];
        j++;
    }
    arrOper[j] = '\0';
    i--;
}

void minuss(int *arrNums,char *arrOper, int i)
{
    arrNums[i] = arrNums[i] - arrNums[i + 1];
    int j{};
    if (arrNums[i + 1] != '\0')
        j = i + 1;
    else
        j = i;
    while (arrNums[j + 1] != '\0') {
        arrNums[j] = arrNums[j + 1];
        j++;
    }
    arrNums[j] = '\0';
    j = i;
    while (arrOper[j] != '\0')
    {
        arrOper[j] = arrOper[j + 1];
        j++;
    }
    arrOper[j] = '\0';
    i--;
}

void umnojenie(int *arrNums,char *arrOper, int i)
{
    arrNums[i] = arrNums[i] * arrNums[i + 1];
    int j{};
    if (arrNums[i + 1] != '\0')
        j = i + 1;
    else
        j = i;
    while(arrNums[j + 1] != '\0')
    {
        arrNums[j] = arrNums[j + 1];
        j++;
    }
    arrNums[j] = '\0';
    j = i;
    while(arrOper[j] != '\0')
    {
        arrOper[j] = arrOper[j + 1];
        j++;
    }
    arrOper[j] = '\0';
    i--;
}

void delenie(int *arrNums,char *arrOper, int i)
{
    arrNums[i] = arrNums[i] / arrNums[i + 1];
    int j{};
    if (arrNums[i + 1] != '\0')
        j = i + 1;
    else
        j = i;
    while(arrNums[j + 1] != '\0')
    {
        arrNums[j] = arrNums[j + 1];
        j++;
    }
    arrNums[j] = '\0';
    j = i;
    while(arrOper[j] != '\0')
    {
        arrOper[j] = arrOper[j + 1];
        j++;
    }
    arrOper[j] = '\0';
    i--;
}

void skobki(int *arrNums, char *arrOper, int i)
{
    for (int j = i + 1; j != ')' ; j++)
    {
        for (int k = j; arrOper[i] != '\0'; i++)
        {
            if (arrOper[i] == '*')
            {
                umnojenie(arrNums,arrOper,k);
            }
        }
        for(int k = j; arrOper[i] != '\0'; i++)
        {
            if (arrOper[i] == '/')
            {
                delenie(arrNums,arrOper, k);
            }
        }
        for(int k = j; arrOper[i] != '\0'; i++)
        {
            if (arrOper[i] == '+')
            {
                pluss(arrNums,arrOper,k);
            }
        }
        for(int k = j; arrOper[i] != '\0'; i++) {
            if (arrOper[i] == '-')
            {
                minuss(arrNums, arrOper, k);
            }
        }
    }
}
#pragma endregion FunkCalculator



int main() {


#pragma region "Calculator"

char *array = new char[30]{};

cout << "Enter your primer: " << endl;
cin.getline(array,30);



cout << endl;
int *arrNums = new int[30];
char *arrOper = new char[30];
char *arrOperSkobkiNums = new char[30];
char *arrOperSkobki = new char[30];
int *arrNumsSkobki = new int[30];

int countOper{};
int countNums{};
int countOperSkobkiNums{};


for (int i = 0; i < 30; i++)
{
    if (char(array[i]) >= 42 && char(array[i]) <=43)
    {
        arrOper[countOper] = array[i];
        countOper++;
    }
    else if (char(array[i]) >= 40 && char(array[i]) <=41)
    {
        arrOperSkobkiNums[countOperSkobkiNums] = array[i];
        countOperSkobkiNums++;
    }
    else if (char(array[i]) == 45)
    {
        arrOper[countOper] = array[i];
        countOper++;
    }
    else if (char(array[i]) == 47)
    {
        arrOper[countOper] = array[i];
        countOper++;
    }
    else if (array[i] >= 48 && array[i] <= 57)
    {
        arrNums[countNums] = array[i] - 48;
        countNums++;
    }

}
cout << endl;


// 3 + ( 5 * 4 )

//nums = 3 5 4
//opers = + *
//skobkaOper = ( * )


for (int i = 0; arrOper[i] != '\0'; i++)
{
    if (arrOper[i] == '(')
    {
        skobki(arrNums,arrOper,i);
    }
}

for (int i = 0; arrOper[i] != '\0'; i++)
{
    if (arrOper[i] == '*')
    {
        umnojenie(arrNums,arrOper,i);
    }
}

for(int i = 0; arrOper[i] != '\0'; i++)
{
    if (arrOper[i] == '/')
    {
        delenie(arrNums,arrOper, i);
    }
}
for(int i = 0; arrOper[i] != '\0'; i++)
{
    if (arrOper[i] == '+')
    {
        pluss(arrNums,arrOper,i);
    }
}
for(int i = 0; arrOper[i] != '\0'; i++) {
    if (arrOper[i] == '-')
    {
        minuss(arrNums, arrOper, i);
    }
}

cout << arrNums[0];







#pragma endregion "Calculator"







    return 0;
}
