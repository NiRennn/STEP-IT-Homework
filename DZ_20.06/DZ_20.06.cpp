#include "DZ_20.06.h"


void createComputer(Computer &PC)
{
    PC.motherboard->createMotherboard();
    PC.operativka->createRAM();
    PC.videocard->createVideoCard();

}

void printAllComponents(Computer PC)
{
    PC.motherboard->printMotherboard();
    PC.motherboard->processor->printCPU();
    PC.operativka->printRAM();
    PC.videocard->printVideoCard();
}


int main() {

    bool progr = true;
    int  choice{};

    CPU *cpu = new CPU("c1", 2.9f, 1.5f, 2);
    Motherboard *m1 = new Motherboard("m1", "m2",*cpu);
    RAM *r1 = new RAM("r1", "r2", 5, 2.5f);
    VideoCard *v1 = new VideoCard(12, "v1", 7, 9);

    Computer* PC = new Computer(*m1, *r1, *v1);

    do {

        cout << "Enter your choice: " << endl
             << "1. Create computer" << endl
             << "2. Print all components" << endl
             << "3. Exit program" << endl;
        cin >> choice;

        while (choice < 1 || choice > 3)
        {
            cout << "Invalid choice! Re-enter your choice: "; cin >> choice;
        }
        if (choice == 1)
        {
            createComputer(*PC);
        }
        if (choice == 2)
        {
            printAllComponents(*PC);
        }
        if (choice == 3)
        {
            progr = false;
        }

    }
    while(progr == true);



    return 0;
}
