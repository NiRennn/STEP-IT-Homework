#include <iostream>
using namespace std;


#pragma region Task1Funk

template <typename T>

T foo(T *_arr,T &_min,T &_max,T &_len)
{
	for (T i = 0; i < _len; i++)
	{
		if (_arr[i] < _min)
		{
			_min = _arr[i];
		}
		if (_arr[i] > _max)
		{
			_max = _arr[i];
		}
	}

	return 0;
}
#pragma endregion Task1Funk

#pragma region Task2Funk

template <typename T>

T foo(T* _arr, T& _result, T& _len)
{
	for (int i = 0; i < _len; i++)
	{
		_result += _arr[i];
	}
	_result /= _len;
	return 0;
}

#pragma endregion Task2Funk

#pragma region Task3Funk

template <typename T>

T foo(T* _arr,T& _result, T& _len)
{
	for (T i = 0; i < _len; i++)
	{
		_result = _arr[i];
		for (T j = _arr[i]; j > 1; j--)
		{
			_result *= (_arr[i] - 1);
			_arr[i]--;
		}
		cout << _result << endl;
	}

	return 0;
}

#pragma endregion Task3Funk

#pragma region Task4Funk

template <typename T>

T foo(T* _arr, T& _result, T& _len)
{
	T _result1{};
	for (T i = 0; i < _len; i++)
	{
		_result1 = _arr[i];
		for (T j = _arr[i]; j > 1; j--)
		{
			_result1 *= (_arr[i] - 1);
			_arr[i]--;
		}
		_result += _result1;
	}

	return _result;
}

#pragma endregion Task4Funk


int main()
{

#pragma region Task1


int main()
{
	int min{ 999 }, max{}, len{ 5 };
	int* arr = new int[len] { 1, 2, 3, 4, 5 };

	foo(arr, min, max, len);
	cout << min << " : " << "Min" << endl;
	cout << max << " : " << "Max" << endl;

	return 0;
}
#pragma endregion

#pragma region Task2



int main()
{
	int result{}, len{ 5 };
	int* arr = new int[len] { 1, 2, 3, 4, 5 };

	foo(arr, result, len);
	cout << result << " : "<< "average of array" << endl;

	return 0;
}

#pragma endregion

#pragma region Task3



int main()
{
	int result{1}, len{ 6 };
	int* arr = new int[len] { 1, 2, 3, 4, 5, 6 };

	foo(arr, result, len);


	return 0;
}

#pragma endregion

#pragma region Task4



int main()
{
	int result{}, len{ 5 };
	int* arr = new int[len] { 1, 2, 3, 4, 5,};

	cout << foo(arr, result, len);

	return 0;
}

#pragma endregion

    return 0;
}
