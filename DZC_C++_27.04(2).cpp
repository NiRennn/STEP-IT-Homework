#include <iostream>
using namespace std;
//
//
//struct Student{
//    char *surname = new char[30];
//    int *group{};
//    int *grades = new int[5];
//
//    void printInfo() {
//        cout << "Surname: " << surname << endl
//             << "Group: " << group << endl;
//
//        cout << "Grades: ";
//        for (int i = 0; i < 5; i++) {
//        cout << grades[i] << " ";
//        }
//        cout << endl;
//        cout << "----------------" << endl;
//    }
//
//
//
//};
//
//
//struct School{
//
//    uint16_t schoolCapacity{10};
//    uint16_t countStudents{};
//
//    Student *stud = new Student{};
//
//    void createStudent() {
//        if (countStudents < schoolCapacity) {
//
//            cout << "Enter surname: ";
//            cin.getline(stud->surname, 30);
//
//            cout << "Enter group: ";
//            cin >> stud->group;
//
//            cout << "Enter grades(2 - 5): " << endl;
//            for (int i = 0; i < 5; i++) {
//                int g{};
//                cout << "Grade " << i + 1 << " : ";
//                cin >> g;
//                while (g < 2 || g > 5) {
//                    cout << "Wrong grade! Re-enter: ";
//                    cin >> g;
//                }
//
//                stud->grades[i] = g;
//            }
//            stud[countStudents] = *stud;
//            countStudents++;
//
//        } else {
//            cout << "School is full!" << endl;
//        }
//
//    getchar();
//    }
//
//
//    void printAll()
//    {
//        for (int i = 0; i < countStudents; i++)
//        {
//            cout << "Student №" << i + 1 << endl;
//            stud[i].printInfo();
//        }
//    }
//
//
//    void printExcellent()
//    {
//        for (int i = 0; i < countStudents; i++)
//        {
//            int gradesExc{};
//            for (int j = 0; j < 5; j++)
//            {
//                if(stud->grades[j] >= 4)
//                gradesExc++;
//
//            }
//            if(gradesExc >= 4)
//                cout << stud->surname << endl;
//        }
//
//    }
//
//
//    void printTwos()
//    {
//        for (int i = 0; i < countStudents; i++)
//        {
//            int gradesTwos{};
//            for (int j = 0; j < 5; j++)
//            {
//                if(stud->grades[j] <= 3)
//                    gradesTwos++;
//            }
//            if(gradesTwos >= 3)
//                cout << stud->surname << endl;
//        }
//    }
//
//
//
//
//    void dynamicChange()
//    {
//        int capacity{};
//        cout << "Enter new capacity: ";
//        cin >> capacity;
//
//        School *newStud = new School[capacity]{};
//
//        Student *newstud = new Student[capacity];
//        for (int i = 0; i < capacity; i++)
//        {
//            for (int j = i; j < capacity; j++)
//            {
//                newstud->surname[i] = stud->surname[j];
//                newstud->group[i] = stud->group[j];
//                newstud->grades[i] = stud->grades[j];
//                break;
//            }
//        }
//    }
//
//};








//int main() {
//
//int choice{};
//
//School *student = new School{};
//
//while(true) {
//    cout << "1.Dynamically change the array " << endl
//         << "2.Print a list of excellent students " << endl
//         << "3. Print a list of twos" << endl
//         << "4. Print all students " << endl
//         << "5. Create a student " << endl;
//
//    cout << "Enter what you want: ";
//    cin >> choice;
//    getchar();
//
//
//    switch (choice) {
//        case 1:
//            system("cls");
//            student->dynamicChange();
//            break;
//
//        case 2:
//            system("cls");
//            student->printExcellent();
//            break;
//
//        case 3:
//            system("cls");
//            student->printTwos();
//            break;
//
//        case 4:
//            system("cls");
//            student->printAll();
//            break;
//
//        case 5:
//            system("cls");
//            student->createStudent();
//    }
//}
//
//    return 0;
//}






struct Man
{
    char *surname = new char[30];
    char *name = new char[30];
    int age;
    int *birthdate = new int[3];


    void printOne()
    {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Birthdate(DD,MM,YYYY): ";
        for (int i = 0; i < 3; i++)
        {
            cout << birthdate[i] << '.';
        }
        cout << endl;

    }
};



struct Person{

    uint16_t personCapacity{5};
    uint16_t countPerson{};

    Man *pers = new Man[personCapacity]{};

    void createPerson()
    {
        Man *man = new Man();

        if (countPerson < personCapacity) {
            cout << "Enter Surname: ";
            cin.getline(man->surname, 30);
            cout << endl;

            cout << "Enter Name: ";
            cin.getline(man->name,30);
            cout << endl;

            cout << "Enter age:";
            cin >> man->age;
            cout << endl;

            cout << "Enter birth date: " << endl;
            cout << "Day: ";
            cin >> man->birthdate[0];
            cout << endl;
            cout << "Month: ";
            cin >> man->birthdate[1];
            cout << endl;
            cout << "Year: ";
            cin >> man->birthdate[2];
            cout << endl;

            pers[countPerson] = *man;
            countPerson++;
        }
        else
        {

        }
    }


    void PrintAllPerson()
    {
        for(int i = 0; i < countPerson; i++)
        {
            cout << "Person #" << i + 1 << endl;
            pers[i].printOne();

        }
    }


    void DeletePerson(){
        int number{};

        PrintAllPerson();

        cout << endl;
        cout <<"Enter person to delete: " << endl;
        cin >> number;
        getchar();

            pers[number - 1].surname = nullptr;
            pers[number - 1].name = nullptr;
            pers[number - 1].age = 0;
            for (int i = 0; i < 3; i++)
            {
                pers[number - 1].birthdate[i] = 0;
            }

    }

    void EditPerson()
    {
        int number{};
        PrintAllPerson();

        cout << "Enter person to edit" << endl;
        cin >> number;
        getchar();


    }


    void printBirthday()
    {
        int month{};
        cout << "Enter month" << endl;
        cin >> month;
        while(month <= 1 || month > 12)
        {
            cout << "Re-enter month" << endl;
            cin >> month;
        }

        for (int i = 0; i < personCapacity; ++i)
        {
            if(pers[i].birthdate[1] == month)
            {
                pers[i].printOne();
            }

        }

    }



    void searchName()
    {
        int num{};
        cout << "How you need to search? " << endl;
        cout << "1. Name" << endl
             << "2. Surname" << endl;
        cin >> num;
        char *search = new char[30];

        switch(num)
        {
            case 1:
                cout << "Enter name to search: " << endl;
                getchar();
                cin.getline(search, 30);


                for (int i = 0; i < personCapacity; ++i)
                {
                    int lenPers{};

                    for(int j = 0; pers[i].name[j] != '\0'; ++j)
                        lenPers++;

                    int yes{};
                    for(int j = 0; j < lenPers; ++j)
                    {
                        if(pers[i].name[j] == search[j])
                            yes++;

                    }

                    if (yes == lenPers)
                        pers[i].printOne();
                }
                break;


            case 2:
                cout << "Enter surname to search: " << endl;
                getchar();
                cin.getline(search, 30);


                for (int i = 0; i < personCapacity; ++i)
                {
                    int lenPers{};

                    for(int j = 0; pers[i].surname[j] != '\0'; ++j)
                        lenPers++;

                    int yes{};
                    for(int j = 0; j < lenPers; ++j)
                    {
                        if(pers[i].surname[j] == search[j])
                            yes++;

                    }

                    if (yes == lenPers)
                        pers[i].printOne();
                }
                break;
        }
    }

    void PrintSorted(Man** person)
    {
        int choice{};
        cout << "How do you want to sort?" << endl
             << "1. By name" << endl
             << "2. By surname" << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                for (size_t i = 0; person[i] != nullptr; i++)
                {
                    for (size_t j = 0; person[j] != nullptr; j++)
                    {
                        if((int) person[i]->name[0] < (int) person[j]->name[0])
                        {
                            char* rev = person[i]->name;
                            int swap{};
                            int *swp = new int[3];
                            person[i]->name = person[j]->name;
                            person[j]->name = rev;

                            rev = person[i]->surname;
                            person[i]->surname = person[j]->surname;
                            person[j]->surname = rev;

                            swap = person[i]->age;
                            person[i]->age = person[j]->age;
                            person[j]->age = swap;

                            swp = person[i]->birthdate;
                            person[i]->birthdate = person[j]->birthdate;
                            person[j]->birthdate = swp;
                        }
                    }
                }

                break;
            case 2:
                for (size_t i = 0; person[i] != nullptr; i++)
                {
                    for (size_t j = 0; person[j] != nullptr; j++)
                    {
                        if((int) person[i]->surname[0] < (int) person[j]->surname[0])
                        {
                            char* rev = person[i]->surname;
                            int swap{};
                            int *swp = new int[3];
                            person[i]->surname = person[j]->surname;
                            person[j]->surname = rev;

                            rev = person[i]->name;
                            person[i]->name = person[j]->name;
                            person[j]->name = rev;

                            swap = person[i]->age;
                            person[i]->age = person[j]->age;
                            person[j]->age = swap;

                            swp = person[i]->birthdate;
                            person[i]->birthdate = person[j]->birthdate;
                            person[j]->birthdate = swp;
                        }
                    }
                }
                break;
        }
    }



};













int main(){

    Person *person = new Person{};

    int choice{};

    while(true){
        cout << "1. Print info with sorting by surname and name " << endl
             << "2. Display lists of birthdays " << endl
             << "3. Search by surname and name " << endl
             << "4. Edit mode " << endl;

    cout << "Enter what you want: ";
    cin >> choice;
    getchar();


    switch (choice) {
        case 1:
            system("cls");
            person->PrintSorted();
            person->PrintAllPerson();
            break;

        case 2:
            system("cls");
            person->printBirthday();
            break;

        case 3:
            system("cls");
            person->searchName();
            break;

        case 4:
            system("cls");
            int choice5{};
            cout << "Create(1), edit(2) or delete(0)? "<< endl;
            cin >> choice5;
            getchar();
            if (choice5 == 1) {
                person->createPerson();
            }
            else if (choice5 == 0) {
                person->EditPerson();
            }
            else if (choice5 == 2) {
                person->DeletePerson();

            }
    }


    }





    return 0;
}
