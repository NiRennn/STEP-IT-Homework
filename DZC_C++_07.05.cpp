#include <iostream>
using namespace std;

struct Student
{
    char *studentName = new char[30];
    char *studentSurname = new char[30];
    int studentAge{};
    char *faculty = new char[30];
    int GPA{};
    int course{};

    void printOneStudent()
    {
        cout << "Name: " << studentName << endl;
        cout << "Surname: " << studentSurname << endl;
        cout << "Age: " << studentAge << endl;
        cout << "Faculty: " << faculty << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Course: " << course << endl;
    }

};



struct Academy
{
    char *AcademyName = new char[30];
    uint16_t countStudents{};
    uint16_t academyCapacity = 10;

    Student *students{};

    void addStudent()
    {
        Student *s = new Student{};

        cout << "Enter student name: ";
        cin.getline(s->studentName,30);

        cout << "Enter student surname: ";
        cin.getline(s->studentSurname,30);

        cout << "Enter students age: ";
        cin >> s->studentAge;
        getchar();

        cout << "Enter student faculty:";
        cin.getline(s->faculty,30);

        cout << "Enter student GPA: ";
        cin >> s->GPA;

        int tmp{};
        cout << "Enter students course(1-4): ";
        cin >> tmp;
        while(tmp > 4 || tmp < 1)
        {
            cout << "Wrong number! Re-enter students course(1-4): ";
            cin >> tmp;
        }
        s->course = tmp;

        students[countStudents] = *s;
        countStudents++;


    }

    void deleteStudent()
    {
        printAllStudents();
        int number{};
        cout << "Enter student number to delete" << endl;
        cin >> number;

        students[number - 1].studentName = nullptr;
        students[number - 1].studentSurname = nullptr;
        students[number - 1].studentAge = 0;
        students[number - 1].faculty = nullptr;
        students[number - 1].GPA = 0;
        students[number - 1].course = 0;


        countStudents--;
    }


    void printFacultyStudents()
    {
        printAllStudents();
        int fac;
        cout << "Enter faculty to print students: ";
        cin >> fac;
        for (int i = 0; i < academyCapacity; i++)
            if (students[i].course == fac)
                students[i].printOneStudent();
    }


    void printAllStudents() {
        for (int i = 0; i < countStudents; i++) {
            cout << "Student #" << i + 1 << endl;
            students[i].printOneStudent();

        }
    }


};

void createAcademy(Academy *&acad)
{
    acad = new Academy{};

    cout << "Enter name of academy: ";
    cin.getline(acad->AcademyName,30);

    cout << "Enter academy capacity:";
    cin >> acad->academyCapacity;
    getchar();

    acad->students = new Student[acad->academyCapacity]{};
}


int main() {

int choice{};

Academy *acad{};

createAcademy(acad);

while(true)
{
    cout << "Enter what to do: " << endl;
    cout << "1. Add student" << endl
         << "2. Delete student" << endl
         << "3. Print all students in one faculty" << endl;

    cin >> choice;
    getchar();

    switch(choice)
    {
        case 1:
            system("cls");
            acad->addStudent();
            break;

        case 2:
            system("cls");
            acad->deleteStudent();
            break;

        case 3:
            system("cls");
            acad->printFacultyStudents();
            break;
    }
}



    return 0;
}
