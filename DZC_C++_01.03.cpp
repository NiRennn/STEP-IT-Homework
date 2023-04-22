#include <iostream>
using namespace std;
int main()
{
	int* arr = (int*)calloc(10, 10 * sizeof(int));
	int arr2[10]{};
	int j{};

	for (int i = 0; i < 10; ++i)
	{
		cout << "Enter value: ";
		cin >> arr[i];
	}

	for (int i = 0; i < 10; ++i)
	{
		if (arr[i] != 0)
		{
			arr2[j] = arr[i];
			j++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (arr2[i] == 0)
		{
				arr2[i] = -1;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i];
	}



int* arr = (int*)calloc(5, 5 * sizeof(int));
int* arr2 = (int*)calloc(5, 5 * sizeof(int));
int* arr10 = (int*)calloc(10, 10 * sizeof(int));
int j{};

for (int i = 0; i < 5; i++)
{
cout << "Enter value for first mass: ";
cin >> arr[i];
}
for (int i = 0; i < 5; i++)
{
cout << "Enter value for second mass: ";
cin >> arr2[i];
}

for (int i = 0; i < 5; i++)
{
	if (arr[i] > 0)
	{
		arr10[j] = arr[i];
		j++;
	}
	if (arr2[i] > 0)
	{
		arr10[j] = arr2[i];
		j++;
	}
}

for (int i = 0; i < 5; i++)
{
	if (arr[i] == 0)
	{
		arr10[j] = arr[i];
		j++;
	}
	if (arr2[i] == 0)
	{
		arr10[j] = arr[i];
		j++;
	}
}
for (int i = 0; i < 5; i++)
{
	if (arr[i] < 0)
	{
		arr10[j] = arr[i];
		j++;
	}
	if (arr2[i] < 0)
	{
		arr10[j] = arr[i];
		j++;
	}
}

for (int i = 0; i < 10; i++)
{
	cout << arr10[i];
}


return 0;
}
