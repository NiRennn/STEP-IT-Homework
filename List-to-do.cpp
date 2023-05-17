#include <iostream>
using namespace std;
#include <cstring>

struct Dela
{
    char *nameCase = new char[40];
    int priority{};
    char *description = new char[100];
    int *date = new int[3];
    int *time = new int[2];

    void printOneDelo()
    {
        cout << "Name: " << nameCase << endl;
        cout << "Priority: " << priority << endl;
        cout << "Description: " << description << endl;
        cout << date[0] << '.' << date[1] << '.' << date[2] << endl;
        cout << "Time: " << time[0] << '.' << time[1] << endl;
    }

    char* charToString()
    {
        char *str = new char[1500]{};
        sprintf_s(str, 1500, "%s\n%d\n%s\n%d\n%d\n%d\n%d\n%d\n", nameCase, priority, description, date[0],date[1],date[2], time[0], time[1]);

        return str;
    }
};

struct Raspisanie
{
    uint16_t casesCapacity{20};
    uint16_t casesCount = 0;

    Dela *spis = new Dela[casesCapacity];

    void createCase()
    {

        Dela *d = new Dela{};

        cout << "CREATING CASE MENU" << endl;
        cout  << endl;

        cout << "Enter name of case: ";
        cin.getline(d->nameCase,40);

        cout << "Enter priority from 1 to 5(1-low priority, 5-high priority): ";
        int tmp{};
        cin >> tmp;
        while(tmp < 1 || tmp > 5)
        {
            cout << "Invalid input! ";
            cin >> tmp;
        }
        d->priority = tmp;
        tmp = 0;
        getchar();

        cout << "Enter description of case: ";
        cin.getline(d->description,100);

        cout << "Enter date of case(DD.MM.YYYY): ";

        cout << "Day: "; cin >> tmp;
        while(tmp < 1 || tmp > 31)
        {
            cout << "Invalid input! " << endl;
            cin >> tmp;
        }
        d->date[0] = tmp;
        tmp = 0;

        cout << "Month: "; cin >> tmp;
        while(tmp < 1 || tmp > 12)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        d->date[1] = tmp;
        tmp = 0;

        cout << "Year: "; cin >> tmp;
        while(tmp < 1900 || tmp > 2023)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        d->date[2] = tmp;
        tmp = 0;

        cout << "Enter time of case(HH.MM): " << endl;
        cout << "Hours: "; cin >> tmp;
        while(tmp < 1 || tmp > 24)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        d->time[0] = tmp;
        tmp = 0;

        cout << "Minutes: "; cin >> tmp;
        while(tmp < 1 || tmp > 60)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        d->time[1] = tmp;


        spis[casesCount] = *d;
        casesCount++;

        system("cls");
    }

    void saveToFile()
    {
        FILE *file{};
        fopen_s(&file, "case.txt","a+");

        if (file == nullptr)
            return;
        fprintf(file,"%s",spis->charToString());
        fclose(file);

    }

    void printAllCases()
    {
        for(int i = 0; i < casesCount; i++)
        {
            cout << "Case #" << i + 1 << endl;
            spis[i].printOneDelo();
        }
    }

    void deleteCase()
    {
        int number{};

        printAllCases();

        cout << "Enter number of case to delete: ";
        cin >> number;
        getchar();

        int index = number - 1;
        for (int i = 0; i < casesCount; i++)
        {
            if (spis[i].nameCase == nullptr)
                break;

            index++;
            spis[i].nameCase = spis[i+ 1].nameCase;
            spis[i].priority = spis[i + 1].priority;
            spis[i].description = spis[i + 1].description;
            spis[i].date = spis[i + 1].date;
            spis[i].time = spis[i + 1].time;

        }
        spis[index].nameCase = nullptr;
        spis[index].priority = 0;
        spis[index].description = nullptr;
        spis[index].date = nullptr;
        spis[index].time = nullptr;
        casesCount--;

        FILE *file{};
        fopen_s(&file, "case.txt","w");

        if (file == nullptr)
            return;
        for (int i = 0; i < casesCount; i++) {
            fprintf(file, "%s", spis[i].charToString());
        }
            fclose(file);
    }

    void editCase()
    {
        printAllCases();

        int number{};

        cout << "Enter number of case to edit: "; cin >> number;
        getchar();

        cout << "Enter new name of case: ";
        cin.getline(spis[number - 1].nameCase,40);

        cout << "Enter new priority from 1 to 5(1-low priority, 5-high priority): ";
        cin >> spis[number - 1].priority;
        getchar();

        cout << "Enter new description for case: ";
        cin.getline(spis[number - 1].description,100);

        int tmp{};
        cout << "Enter new date for case: ";
        cout << "Day: "; cin >> tmp;
        while(tmp < 1 || tmp > 31)
        {
            cout << "Invalid input! " << endl;
            cin >> tmp;
        }
        spis->date[0] = tmp;
        tmp = 0;

        cout << "Month: "; cin >> tmp;
        while(tmp < 1 || tmp > 12)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        spis->date[1] = tmp;
        tmp = 0;

        cout << "Year: "; cin >> tmp;
        while(tmp < 1900 || tmp > 2023)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        spis->date[2] = tmp;
        tmp = 0;

        cout << "Enter new time of case(HH.MM): " << endl;
        cout << "Hours: "; cin >> tmp;
        while(tmp < 1 || tmp > 24)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        spis->time[0] = tmp;
        tmp = 0;

        cout << "Minutes: "; cin >> tmp;
        while(tmp < 1 || tmp > 60)
        {
            cout << "Invalid input! Re-enter: ";
            cin >> tmp;
        }
        spis->time[1] = tmp;

        FILE *file{};
        fopen_s(&file, "case.txt","w");

        if (file == nullptr)
            return;
        fprintf(file,"%s",spis->charToString());
        fclose(file);
    }

    void searchCases(Raspisanie *dela)
    {
        int search{};

        cout << "Choose how to search: " << endl
             << "1. By name" << endl
             << "2. By priority" << endl
             << "3. By description" << endl
             << "4. By date" << endl
             << "5. By time" << endl;
        cin >> search;
        getchar();

        switch(search)
        {
            case 1:
                system("cls");
                searchName();
                break;

            case 2:
                system("cls");
              searchPriority();
                break;

            case 3:
                system("cls");
                searchDescription();
                break;

            case 4:
                system("cls");
                searchDate();
                break;

            case 5:
                system("cls");
                searchTime();
                break;

        }
    }

    void searchName()
    {
        char *findName = new char[40];
        int countLen{};

        cout << "Enter name for search: " << endl;
        cin.getline(findName,40);

        for (int i = 0; i < casesCount; i++)
        {
            for (int j = 0; j < strlen(findName); j++)
            {
                if (findName[j] == spis[i].nameCase[j])
                    countLen++;
            }
            if (countLen == strlen(findName))
                spis[i].printOneDelo();
        }
    }

    void searchPriority()
    {
        int tmp{};

        cout << "Enter priority for search: " << endl;
        cin >> tmp;

        for (int i = 0; i < casesCount; i++)
        {
            if (tmp == spis[i].priority)
                spis[i].printOneDelo();
        }
    }

    void searchDescription()
    {
        char *findDescription = new char[40];
        int countLen{};

        cout << "Enter name for search: " << endl;
        cin.getline(findDescription,40);

        for (int i = 0; i < casesCount; i++)
        {
            for (int j = 0; j < strlen(findDescription); j++)
            {
                if (findDescription[j] == spis[i].description[j])
                    countLen++;
            }
            if (countLen == strlen(findDescription))
                spis[i].printOneDelo();
        }
    }

    void searchDate()
    {
        int *findDate = new int[3];

        cout << "Enter date for search(DD.MM.YYYY): " << endl;
        cout << "Day:"; cin >> findDate[0];
        cout << "Month:"; cin >> findDate[1];
        cout << "Year:"; cin >> findDate[2];

        for (int i = 0; i < casesCount; i++)
        {
            int countSovp{};
            for (int j = 0; j < 3; j++)
            {
                if (findDate[j] == spis[i].date[j])
                    countSovp++;

                if (countSovp == 3)
                    spis[i].printOneDelo();
            }
        }
    }

    void searchTime()
    {
        int *findTime = new int[2];

        cout << "Enter time for search(HH.MM): " << endl;
        cout << "Hours:"; cin >> findTime[0];
        cout << "Minute:"; cin >> findTime[1];

        for (int i = 0; i < casesCount; i++)
        {
            int countSovp{};
            for (int j = 0; j < 2; j++)
            {
                if (findTime[j] == spis[i].time[j])
                    countSovp++;

                if (countSovp == 2)
                    spis[i].printOneDelo();
            }
        }
    }

    void showCases()
    {
        int number{};
        int number1{};
        int *showDay = new int[3];
        int *showMonth = new int[2];
        Dela *vivodDay = new Dela[casesCount];
        Dela *vivodmonth = new Dela[casesCount];

        int tmp = 0;

        Dela *tmp2 = new Dela[1]{};

        cout << "To-do list display by: " << endl
             << "1. Day " << endl
             << "2. Month " << endl;
        cin >> number;

        switch (number) {
            case 1:

                cout << "Enter day: "; cin >> showDay[0];
                cout << "Enter month: "; cin >> showDay[1];
                cout << "Enter year: "; cin >> showDay[2];

                cout << "How to sort?" << endl
                     << "1. By priority" << endl
                     << "2. By date and time" << endl;
                cin >> number1;

                    for (int i = 0; i < casesCount; i++)
                    {
                        int countSovp{};
                        for (int j = 0; j < 3; j++)
                        {
                            if (showDay[j] == spis[i].date[j])
                                countSovp++;

                            if (countSovp == 3)
                            {
                                vivodDay[tmp] = spis[i];
                                tmp++;
                            }
                        }
                    }
                if (number1  == 1)
                {
                    for (int i = 0; i < tmp; i++)
                    {
                        if (vivodDay[i].priority < vivodDay[i + 1].priority)
                        {
                            tmp2[0] = vivodDay[i];
                            vivodDay[i] = vivodDay[i + 1];
                            vivodDay[i + 1] = tmp2[0];
                        }
                    }
                    for (int i = 0; i < tmp; i++)
                    {
                        vivodDay[i].printOneDelo();
                    }
                }
                else if (number1 == 2)
                {
                    for (int i = 0; i < tmp; i++)
                    {
                        for (int j = i + 1; j < tmp; j++)
                        {
                            if (vivodDay[i].date[2] > vivodDay[j].date[2] ||
                            vivodDay[i].date[2] == vivodDay[j].date[2] &&
                            vivodDay[i].date[1] > vivodDay[j].date[1] ||
                            vivodDay[i].date[2] == vivodDay[j].date[2] &&
                            vivodDay[i].date[1] == vivodDay[j].date[1] &&
                            vivodDay[i].date[0] > vivodDay[j].date[0])
                            {
                                tmp2[0] = vivodDay[i];
                                vivodDay[i] = vivodDay[i + 1];
                                vivodDay[i + 1] = tmp2[0];
                            }
                        }
                    }
                    for (int i = 0; i < tmp; i++) {
                        vivodDay[i].printOneDelo();
                    }
                }
                delete[] vivodDay;
                break;

            case 2:
                cout << "Enter month: "; cin >> showMonth[0];
                cout << "Enter year: "; cin >> showMonth[1];

                cout << "How to sort?" << endl
                     << "1. By priority" << endl
                     << "2. By date and time" << endl;
                cin >> number1;
                    for (int i = 0; i < casesCount; i++)
                    {
                        int countSovp{};

                        if (showMonth[0] == spis[i].date[1])
                            countSovp++;
                        if (showMonth[1] == spis[i].date[2])
                            countSovp++;

                        if (countSovp == 2)
                        {
                            vivodmonth[tmp] = spis[i];
                            tmp++;
                        }
                    }
                if(number1 == 1)
                {
                    for (int i = 0; i < tmp; i++)
                    {
                        if (vivodmonth[i].priority < vivodmonth[i + 1].priority)
                        {
                            tmp2[0] = vivodDay[i];
                            vivodmonth[i] = vivodmonth[i + 1];
                            vivodmonth[i + 1] = tmp2[0];
                        }
                    }
                    for (int i = 0; i < tmp; i++)
                    {
                        vivodmonth[i].printOneDelo();
                    }
                }
                else if (number1 == 2)
                {
                    for ( int i = 0; i < tmp; i++)
                    {
                        for (int j = i + 1; j < tmp; j++)
                        {
                            if (vivodmonth[i].date[2] > vivodmonth[j].date[2] ||
                            vivodmonth[i].date[2] == vivodmonth[j].date[2] &&
                            vivodmonth[i].date[1] > vivodmonth[j].date[1] ||
                            vivodmonth[i].date[2] == vivodmonth[j].date[2] &&
                            vivodmonth[i].date[1] == vivodmonth[j].date[1])
                            {
                                tmp2[0] = vivodmonth[i];
                                vivodmonth[i] = vivodmonth[i + 1];
                                vivodmonth[i + 1] = tmp2[0];
                            }
                        }
                    }
                    for (int i = 0; i < tmp; i++)
                    {
                        vivodmonth[i].printOneDelo();
                    }
                }
                delete[] vivodmonth;

                break;
        }
    }
};

int main() {

#pragma region "List to do"
int choice{};

Raspisanie *dela = new Raspisanie{};

cout << "LIST TO DO" << endl;
bool close = true;
while(close)
{
    cout << "Enter what to do: " << endl
         << "1. Adding cases " << endl
         << "2. Deleting cases " << endl
         << "3. Editing cases " << endl
         << "4. Searching cases " << endl
         << "5. Printing cases " << endl
         << "6. Show all cases " << endl
         << "7. Close program " << endl;

    cin >> choice;
    getchar();

    switch (choice) {
        case 1:
            system("cls");
            dela->createCase();
            dela->saveToFile();
            break;
        case 2:
            system("cls");
            dela->deleteCase();
            break;
        case 3:
            system("cls");
            dela->editCase();
            break;
        case 4:
            system("cls");
            dela->searchCases(dela);
            break;
        case 5:
            system("cls");
            dela->showCases();
            break;
        case 6:
            system("cls");
            dela->printAllCases();
            break;
        case 7:
            close = false;
            break;

    }
}

#pragma endregion "List to do"

    return 0;
}
