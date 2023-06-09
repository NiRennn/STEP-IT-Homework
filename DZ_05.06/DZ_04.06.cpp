#include "DZ_04.06.h"

void createComputer(Computer &PC)
{
    PC.motherboard.createMotherboard();
    PC.processor.createCPU();
    PC.operativka.createRAM();
    PC.videocard.createVideoCard();

}

void printAllComponents(Computer PC)
{
    PC.motherboard.printMotherboard();
    PC.processor.printCPU();
    PC.operativka.printRAM();
    PC.videocard.printVideoCard();
}




int main() {
    bool progr = true;
    int  choice{};
    Computer PC{};

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
            createComputer(PC);
        }
        if (choice == 2)
        {
            printAllComponents(PC);
        }
        if (choice == 3)
        {
            progr = false;
        }

    }
    while(progr == true);

    return 0;
}
