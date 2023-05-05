#include <iostream>
using namespace std;

struct FIO{
    char* Name = new char[30];
    char* Surname = new char[30];
    char* Patronymic = new char[30];
    unsigned int* Grades = new unsigned int[10];
    double* GPA{};



    void printInfo() {
        cout << "Name:  " << Name << endl
            << "Surname: " << Surname << endl
            << "Patronymic: " << Patronymic << endl
            << endl;

        cout << "All grades: " << endl;
        for (int i = 0; i < 10; i++) {
            cout << Grades[i] << " ";
        }
        cout << endl;
        cout << "Grade Point Average: " << GPA;

    }




    double printGPA(){
        double GPA = 0.0;

        for (int i = 0; i < 10; i++) {
            GPA += Grades[i];

        }

        for (int i = 0; i < 10; i++) {
            cout << Grades[i] << " ";
        }
        GPA = GPA / 10;
        cout << endl;
        cout << "Grade Point Average: " << GPA << endl;

    }




};


struct School{

    uint16_t schoolCapacity{10};
    uint16_t countStudents{};

    FIO *stud = new FIO[schoolCapacity]{};

    void createFIO() {
        if (countStudents < schoolCapacity) {
            FIO *fio = new FIO{};

            cout << "Enter Name of student: ";
            cin.getline(fio->Name, 30);
            cout << endl;

            cout << "Enter Surname of student: ";
            cin.getline(fio->Surname, 30);
            cout << endl;

            cout << "Enter Patronymic of student: ";
            cin.getline(fio->Patronymic, 30);
            cout << endl;

            cout << "Enter Grades( 1 - 12 ):" << endl;
            for (int i = 0; i < 10; i++) {
                int g{};
                cout << "Grade " << i + 1 << " : ";
                cin >> g;
                cout << endl;
                while (g < 1 || g > 12) {
                    cout << "Wrong grade! Re-enter: ";
                    cin >> g;
                    cout << endl;
                }

                fio->Grades[i] = g;
            }
            stud[countStudents] = *fio;
            countStudents++;
        } else
            cout << "School is full!" << endl;
    }


        void print()
        {
        stud->printInfo();
        }

        void printgpa()
        {
        stud->printGPA();
        }


    void printAllStudents(){
        for (int i = 0; i < countStudents; i++)
        {
            cout << "Student №" << i + 1 << endl;
            stud[i].printInfo();
        }

    }

    void gradesStudent()
    {
        int choice;

            cout << "Choose student to print grades: ";
            cin >> choice;
            for (int i = 0; i < 10; i++)
            {
                cout << stud[choice].Grades[i];
            }




    }


};







int main() {

int choice{};

School *students = new School{};


while(true){

    cout << "1. Add name, surname and patronymic" << endl
         << "2. Print info " << endl
         << "3. Print GPA" << endl
         << "4. Print all students" << endl;

    cout << "Enter what to do: ";
    cin >> choice;
    getchar();

    switch (choice) {
        case 1:
            system("cls");
            students->createFIO();
            break;

        case 2:
            system("cls");
            students->print();
            break;
        case 3:
            system("cls");
            students->printgpa();
            break;
        case 4:
            system("cls");
            students->printAllStudents();
            break;
        case 5:
            system("cls");
            students->printAllStudents();
            students->gradesStudent();
        default:
            break;
    }
}









    return 0;
}
