#include <iostream>
using namespace std;
#include <string>
#include <fstream>



class Bus
{
public:
    int busNumber;
    string driverName;
    int routeNumber;
    int seatsCount;

    Bus() = default;

    Bus(int number, const string driver, int route, int seats)
        :busNumber(number), driverName(driver), routeNumber(routeNumber), seatsCount(seats) {}



};


class Park
{
public:
    Bus bus;
    Park* left;
    Park* right;

    Park(const Bus& busData) : bus(busData), left(nullptr), right(nullptr) {}
};

Park* insert(Park* root, const Bus& bus)
{
    if (root == nullptr)
    {
        return new Park(bus);
    }

    if (bus.busNumber < root->bus.busNumber)
    {
        root->left = insert(root->left, bus);
    }
    else if (bus.busNumber > root->bus.busNumber)
    {
        root->right = insert(root->right, bus);
    }

    return root;
}

Park* search(Park* root,int busNumber)
{
    if (root == nullptr || root->bus.busNumber == busNumber)
    {
        return root;
    }
    if (busNumber < root->bus.busNumber)
        return search(root->left, busNumber);
    if (busNumber > root->bus.busNumber)
        return search(root->right, busNumber);
}

void printBusInformation(const Bus& bus)
{
    cout << "Bus Number: " << bus.busNumber << endl;
    cout << "Driver: " << bus.driverName << endl;
    cout << "Route Number: " << bus.routeNumber << endl;
    cout << "Count of seats: " << bus.seatsCount << endl;
    cout << endl;

}

void writeToFile(Park* root, ofstream& outFile)
{
    if(root == nullptr){
        return;
    }

    writeToFile(root->left,outFile);
    outFile << "Bus number:" << root->bus.busNumber << " , Driver name: " << root->bus.driverName <<
    " , Route number: " << root->bus.routeNumber << " , Seats: " << root->bus.seatsCount << endl;
    outFile << endl;
    writeToFile(root->right,outFile);
}

void foo(Park* root)
{
    int numberToSearch{};


    cout << "Enter bus number to search: " << endl;
    cin >> numberToSearch;


    Park* busSearch = search(root, numberToSearch);

    if (busSearch != nullptr) {
        printBusInformation(busSearch->bus);
    }
    else {
        cout << "Bus number not found. " << endl;
    }
}

int main() {

    Park* root = nullptr;


    root = insert(root,Bus(12,"Igor Kostolomov",1234,23));
    root = insert(root,Bus (2, "Elnur Mammedov", 1342,30));
    root = insert(root,Bus (5, "Anver Mamedov", 565,21));
    root = insert(root,Bus (111, "Elvin Azimov", 4433, 14));
    root = insert(root,Bus (7, "Ramil Teymurov", 8374,22));
    root = insert(root,Bus (201, "Rufat Aliyev",999, 32));

    int choice{};

    cout << "Welcome to bus park app!" << endl;
    cout << endl;
    do {
        cout << "1. Search by bus number " << endl;
        cout << "2. Write all buses to file " << endl;
        cout << "3. Exit " << endl;
        cout << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;


        switch (choice) {
            case 1:
                foo(root);
                break;


            case 2:
                ofstream outFile("bus.txt");
                writeToFile(root,outFile);
                cout << "Info written to file." << endl;
                outFile.close();
                break;

            case 3:
                cout << "End of program." << endl;
                break;


            default:
                cout << "Invalid choice. Re-enter your option: " << endl;
        }


    } while(choice != 3);




    return 0;
}
