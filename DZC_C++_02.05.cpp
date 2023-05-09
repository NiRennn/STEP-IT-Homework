#include <iostream>
using namespace std;


struct Animal
{
    char *animalName = new char[30]{};
    int age{};
    char *gender = new char[30]{};

    void printAnimal()
    {
        cout << "Name: " << animalName << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};


struct Zoo
{
    char *nameZoo = new char[30]{};
    uint16_t zooCapacity{5};
    uint16_t animalCount{};

    Animal *animals{};


    void CreateAnimal()
    {

        if (animalCount < zooCapacity)
        {
            Animal *a = new Animal{};

            cout << "Enter animal name: ";
            cin.getline(a->animalName,30);

            cout << "Enter animal age: ";
            cin >> a->age;
            getchar();
            cout << "Enter animal gender: ";
            cin.getline(a->gender,30);

            animals[animalCount] = *a;
            animalCount++;

        }
        else
        {
            cout << "Zoo is full!" << endl;
        }
    }

    void deleteAnimal()
    {
        printAll();

        int choice{};

        cout << "Enter number of animal to delete: ";
        cin >> choice;

        getchar();
        int index = choice - 1;
        for (int i = 0; i < animalCount; i++)
        {
            if (animals[i].animalName == nullptr)
                break;

            index++;
            animals[i].animalName = animals[i + 1].animalName;
            animals[i].gender = animals[i + 1].gender;
            animals[i].age = animals[i + 1].age;
        }
        animals[index].animalName = nullptr;
        animals[index].gender = nullptr;
        animals[index].age = 0;
        animalCount--;
    }


    void editAnimal()
    {
        int choice{};

        cout << "Enter number of animals to edit" << endl;
        cin >> choice;

        getchar();

        cout << "Enter new animal name: ";
        cin.getline(animals[choice - 1].animalName,30);

        cout << "Enter new animal gender: ";
        cin.getline(animals[choice - 1].gender,30);

        cout << "Enter new animal age: ";
        cin >> animals[choice - 1].age;

    }


    void printAll()
    {
        for(int i = 0; i < animalCount ; i++)
        {
            cout << i + 1 << " animal: "<< endl;
            animals[i].printAnimal();
        }
    }
};

void CreateZoo(Zoo *&zoo)
{
    zoo = new Zoo{};

    cout << "Enter Zoo name: ";
    cin.getline(zoo->nameZoo,30);

    zoo->animals = new Animal[zoo->zooCapacity]{};
}






int main() {

    int choice{};

    Zoo *zoo{};

    CreateZoo(zoo);

    while (true)
    {
        cout << "Enter what to do: " << endl
             << "1. Add animal" << endl
             << "2. Delete animal" << endl
             << "3. Edit animal" << endl
             << "4. Print all animals" << endl;
        cin >> choice;

        getchar();
        switch (choice) {
            case 1:
                system("cls");
                zoo->CreateAnimal();
                break;
            case 2:
                system("cls");
                zoo->deleteAnimal();

                break;
            case 3:
                system("cls");
                zoo->editAnimal();

                break;
            case 4:
                system("cls");
                zoo->printAll();

                break;

        }
    }









    return 0;
}
