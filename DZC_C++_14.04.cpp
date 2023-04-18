#include <iostream>
using namespace std;

int max( int* A, int* B,int length1, int length2)
{
    int max{};
    for(int i = 0; i < length1; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    for(int i = 0; i < length2; i++)
    {
        if (B[i] > max)
            max = B[i];
    }
    return max;
}

int min( int* A, int* B,int length1, int length2)
{
    int min = 9999;
    for(int i = 0; i < length1; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    for(int i = 0; i < length2; i++)
    {
        if (B[i] < min)
            min = B[i];
    }
    return min;
}

float avg( int* A, int* B,int length1, int length2)
{
    float avg{};
    for(int i = 0; i < length1; i++)
    {
        avg += A[i];
        for (int j = 0; j < length2; j++)
        {
            avg += B[i];
        }
    }
    avg /= length1 + length2;
    return avg;
}

int Action(int* A, int* B, int length1, int length2)
{
    int choice{};
    cout << "Enter your choice:\n "
            "1. Max\n"
            "2. Min\n"
            "3. Avg\n";
    cin >> choice;

switch(choice)
{
    case 1: {
        return max(A, B, length1, length2);
    }
    case 2: {
        return min(A, B, length1, length2);
    }
    case 3: {
        return avg(A, B, length1, length2);
    }
}

}




int main()
{

const int length1 = 7;
const int length2 = 8;
int A [length1] = {10, 15, 9, 7, 33, 18, 47};
int B [length2] = {11, 6, 31, 32, 29, 66, 21, 19};

cout << Action(A, B, length1, length2);







    return 0;
}
