#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //task1

    int year{};
    cout << "Enter year: ";
    cin >> year;
    int days = (year % 4 == 0) ? 366 : 365;
    cout << "In " << year << " = " << days << " days";


    //task2

       float grivna, ostatok{};
       int kop{};

       cout << "Enter count of grivna: ";
       cin >> grivna;
       cout << "Enter count of kopeek: ";
       cin >> kop;
       cout << grivna + (kop / 100) << " grvn " << kop % 100 << " kop";




    //task3



    float a, b, c, volume{};
    cout << "Вычисление объема параллелепипеда.";
    cout << "Введите исходные данные: " << endl;
    cout << "Длина (см) -> ";
    cin >> a;
    cout << "Ширина (см) -> ";
    cin >> b;
    cout << "Высота (см) -> ";
    cin >> c;
    cout << "Объем: " << (a * b * c) << " куб. см.";




    //task4
    float scale, distance{};

    cout << "Вычисление расстояния между населенными пунктами.";
    cout << "Введите исходные данные: ";

    cout << "Масштаб карты (количество километров в одном сантиметре) -> ";
    cin >> scale;
    cout << "Расстояние между точками, изображающими населенные пункты(см) -> ";
    cin >> distance;
    cout << "Расстояние между населенными пунктами " << distance * scale << ".";



    //task5

    float R{};

    cout << "Вычисление объема шара.";
    cout << "Введите радиус шара (см): ";
    cin >> R;
    cout << "Объема шара с радиусом " << R << " равен: " << (4 * 3.14 * R * R * R) / 3 << "см.куб." << endl;


    return 0;


}