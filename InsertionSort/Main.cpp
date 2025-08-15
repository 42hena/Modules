#include <iostream>

void InsertionSort(int* array, int length)
{
	int temp;
	for (int i = 1; i < length; ++i)
	{
		temp = array[i];
		int j;
		for (j = i - 1; j >= 0; --j)
		{
			if (array[j] <= temp) {
				break;
			}
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}

void Print(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int array[] = { 5,4,5,2,1 };
	int length = sizeof(array) / sizeof(array[0]);
	
	Print(array, length);
	InsertionSort(array, length);
	Print(array, length);
}
