#include <iostream>

void SelectionSort(int *array, int length)
{
	int minIdx;
	for (int i = 0; i < length; ++i)
	{
		minIdx = i;
		for (int j = i; j < length; ++j)
		{
			if (array[j] < array[minIdx]) {
				minIdx = j;
			}
		}
		std::swap(array[i], array[minIdx]);
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
	SelectionSort(array, length);
	Print(array, length);
}
