#include <iostream>
#include <algorithm>

void BubbleSort(int* array, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);
			}
		}
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
	int array[] = { 5,4,3,2,1 };
	int length = 5;
	Print(array, length);
	BubbleSort(array, length);
	Print(array, length);
}
