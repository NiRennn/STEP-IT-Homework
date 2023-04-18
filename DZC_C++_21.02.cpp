#include <iostream>
using namespace std;
int main()
{
//	task1

	char symbol;
	cout << "enter letter, number, punctuation mark or another: ";
	cin >> symbol;
	if (symbol >= '0' && symbol <= 9)
	{
		cout << "your symbol is number!";
	}
	else if (symbol >= 'a' && symbol <= 'z')
	{
		cout << "your symbol is lower letter!";
	}
	else if (symbol >= 'a' && symbol <= 'z')
	{
		cout << "your symbol is upper letter!";
	}
	else if (symbol == '.' || symbol == ',' || symbol == '!' || symbol == '?')
	{
		cout << "your symbol is punctuation mark!";

	}
	else
	{
		cout << "your symbol belongs to another!";
	}

//	task2

	int time{}, choice{};

	cout << "enter number of minutes: " << endl;
	cin >> time;
	cout << "1. bakcell - bakcell\n2. bakcell - azercell\n3. bakcell - nar" << endl;
	cout << "4. azercell - azercell\n5. azercell - bakcell\n6. azercell - nar" << endl;
	cout << "7. nar - bakcell\n8. nar - azercell\n9. nar - nar\n" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << time << " minutes cost " << time * 0.6 << " pence." << endl;
		break;
	case 2:
		cout << time << " minutes cost " << time * 0.6 << " pence." << endl;
		break;
	case 3:
		cout << time << " minutes cost " << time * 0.6 << " pence." << endl;
		break;
	case 4:
		cout << time << " minutes cost " << time * 0.4 << " pence." << endl;
		break;
	case 5:
		cout << time << " minutes cost " << time * 0.5 << " pence." << endl;
		break;
	case 6:
		cout << time << " minutes cost " << time * 0.6 << " pence." << endl;
		break;
	case 7:
		cout << time << " minutes cost " << time * 0.3 << " pence." << endl;
		break;
	case 8:
		cout << time << " minutes cost " << time * 0.3 << " pence." << endl;
		break;
	case 9:
		cout << time << " minutes cost " << time * 0 << " pence." << endl;
		break;
	}



int option{}, des1{}, des2{}, delay1{}, delay2{}, lines1{}, lines2{};

cout << "Enter the option number: " << endl;
cout << "1. Vasya's desired income and the number of delays. How many lines of code he needs to write?" << endl;
cout << "2. Number of lines of code written by Vasya and the desired amount of salary. How many times can Vasya be late?" << endl;
cin >> option;


if (option == 1)
{
	cout << "Enter desired income: " << endl;
	cin >> des1;
	cout << "Enter number of delays: " << endl;
	cin >> delay1;
	lines1 = (des1 * 2) + (delay1 / 3 * 20);
	cout << "Vasya need to write " << lines1 << " lines of code.";
}
else if (option == 2)
{
	cout << "Enter number of lines: " << endl;
	cin >> lines2;
	cout << "Enter desired income: " << endl;
	cin >> des2;
	if (lines2 / 2 <= des2)
	{
		cout << "Must not be skipped. " << endl;
	}
	else
	{
		cout << (lines2 / 2 - des2) / 20 << "times can be skipped.";
	}
}

else
{
	cout << "Wrong option...";
}

return 0;
}
