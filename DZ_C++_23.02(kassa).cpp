#include <iostream>
using namespace std;
int main()
{
//task1

int num1{}, num2{}, number{};

cout << "Enter start of diapason: " << endl;
cin >> num1;
cout << "Enter end of diapason: " << endl;
cin >> num2;
cout << "Enter number in diapason: " << endl;
cin >> number;

while (true)
{

	if (number > num1 && number < num2)
	{
		cout << "Gotcha!";
		break;
	}
	else
	{
		cout << "Not in diapason! Try again...";
		cin >> number;

	}
}

//task2

int candy = 10, gingerbread = 5, toys = 10, tangerines = 20, select1{}, select2{}, discount_choice_money{},money = 0, yesorno{}, count{};
    const int candy_price = 5, gingerbread_price = 10, toys_price = 15, tangerines_price = 5;
    bool choice, discount_choice;
    double income{}, money_discount{},select5{}, count2{}, discount_choice_money2{};

    cout << "Welcome to shop!" << endl;
    do {
        cout << "Enter what you need:\n1.Selling\n2.Total Income\n3.Count of goods" << endl;
        cin >> select5;
        select1 = select5;
        while (select1 > 3 || select1 < 1)
        {
            cout << "Wrong number... Choose another choice: " << endl;
            cin >> select1;
        }
        switch (select1) {
            case 1:
                do {
                    cout << endl;
                    cout << "1. Candy " << "- " << candy << "\t\tPrice - " << candy_price << " $." << endl;
                    cout << "2. Gingerbread " << "- " << gingerbread << "\tPrice - " << gingerbread_price << " $." << endl;
                    cout << "3. Christmas toys " << "- " << toys << "\tPrice - " << toys_price << " $." << endl;
                    cout << "4. Tangerines " << "- " << tangerines << "\tPrice - " << tangerines_price << " $." << endl;
                    cout << "5. For end of buying." << endl;
                    cout << endl;
                    cout << "Select number of required product: " << endl;

                    cin >> select5;
                    select2 = select5;
                    while (select2 < 1 || select2 > 5)
                    {
                        cout << "Sorry, wrong number... Re-enter your choice: " << endl;
                        cin >> select2;
                    }
                    switch (select2)
                    {
                        case 1:
                            if (candy == 0)
                            {
                                cout << "Sorry, no candies left...((( Choose another product: " << endl;
                                cin >> select5;
                                select2 = select5;
                            }
                            cout << "Enter count of candy: "; cin >> count2;
                            count = count2;
                            while (count > candy)
                            {
                                cout << "You enter more products than we have... Re-enter count: " <<  endl;
                                cin >> count2;
                                count = count2;
                            }
                            while (count < 0)
                            {
                                cout << "Wrong number... Enter correct count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            candy -= count;
                            money += count * candy_price;
                            cout << "You need to pay for this: " << count * candy_price << endl;
                            break;
                        case 2:
                            if (gingerbread == 0)
                            {
                                cout << "Sorry, no gingerbread left...((( Choose another product: " << endl;
                                cin >> select5;
                                select2 = select5;
                            }
                            cout << "Enter count of gingerbread: "; cin >> count2;
                            count = count2;
                            while (count > gingerbread)
                            {
                                cout << "You enter more products than we have... Re-enter count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            while (count < 0)
                            {
                                cout << "Wrong number... Enter correct count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            gingerbread -= count;
                            money += count * gingerbread_price;
                            cout << "You need to pay for this: " << count * gingerbread_price << endl;
                            break;
                        case 3:
                            if (toys == 0)
                            {
                                cout << "Sorry, no toys left...((( Choose another product: " << endl;
                                cin >> select5;
                                select2 = select5;
                            }
                            cout << "Enter count of toys: "; cin >> count2;
                            count = count2;
                            while (count > toys)
                            {
                                cout << "You enter more products than we have... Re-enter count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            while (count < 0)
                            {
                                cout << "Wrong number... Enter correct count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            toys -= count;
                            money += count * toys_price;
                            cout << "You need to pay for this: " << count * toys_price << endl;
                            break;
                        case 4:
                            if (tangerines == 0)
                            {
                                cout << "Sorry, no tangerines left...((( Choose another product: " << endl;
                                cin >> select5;
                                select2 = select5;
                            }
                            cout << "Enter count of tangerines: "; cin >> count2;
                            count = count2;
                            while (count > tangerines)
                            {
                                cout << "You enter more products than we have... Re-enter count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            while (count < 0)
                            {
                                cout << "Wrong number... Enter correct count: " << endl;
                                cin >> count2;
                                count = count2;
                            }
                            tangerines -= count;
                            money += count * tangerines_price;
                            cout << "You need to pay for this: " << count * tangerines_price << endl;
                            break;
                        case 5:
                            break;
                        default:
                            select2 = 0;
                            break;
                    }

                    cout << "If you want to continue your shopping, press any key. (1 - YES / 0 - NO):" << endl;
                    cin >> select5;
                    select2 = select5;
                    while (select2 < 0)
                    {
                        cout << "Wrong number... Re-enter number: " << endl;
                        cin >> select5;
                        select2 = select5;
                    }
                    while (select2 > 1)
                    {
                        cout << "Wrong number... Re-enter number: " << endl;
                        cin >> select5;
                        select2 = select5;
                    }

                } while (select2);

                cout << "You need to pay: " << money << endl;
                cout << endl;
                cout << "Do you have discount? (1 - YES / 0 - NO)" << endl;
                cin >> yesorno;
                    if (yesorno == 0)
                    {
                        cout << "You need to pay: " << money << " $." << endl;
                        break;
                    }
                    if (yesorno == 1) {
                        cout << "Enter your discount: ";
                        cin >> discount_choice_money;
                        while (discount_choice_money < 0 || discount_choice_money > 100)
                        {
                            cout << "Sorry, entered number can`t be more than 100 and less than 0... Re-enter discount: "
                                 << endl;
                            cin >> discount_choice_money2;
                            discount_choice_money = discount_choice_money2;
                        }
                        income = money - (money / 100  * discount_choice_money);
                        break;
                        }
                    else if (yesorno > 1 || yesorno < 0)
                    {
                        cout << "error";
                        break;
                    }

            case 2:
                income += money;
                cout << "Total income : " << income << " $." << endl;
                cout << endl;
                break;

            case 3:
                cout << "1.Candies left: " << candy << endl;
                cout << "2.Gingerbreads left: " << gingerbread << endl;
                cout << "3.Toys left: " << toys << endl;
                cout << "4.Tangerines left: " << tangerines << endl;
                cout << endl;
                break;
        }
    }while (select1);


	return 0;
}
