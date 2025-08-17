

#include <iostream>

#include <algorithm>

void MergeSort(int array[], int l, int r)
{
	int mid = (l + r) / 2;
	if (l >= r)
	{
		return;
	}
	
	MergeSort(array, l, mid);
	MergeSort(array, mid + 1, r);

	// 합치기.
	int i = 0;
	int lCnt = mid - l + 1;
	int j = 0;
	int rCnt = r - mid;
	
	// 2개 비교하고 합치기.

	int* arr = new int[r - l + 1];
	while (i < lCnt && j < rCnt)
	{
		int lIdx = i + l;
		int rIdx = j + mid + 1;
		if (array[lIdx] > array[rIdx])
		{
			arr[i + j] = array[rIdx];
			j = j + 1;
		}
		else
		{
			arr[i + j] = array[lIdx];
			i = i + 1;
		}
	}

	// 왼쪽만 남은 경우
	while (i < lCnt)
	{
		int lIdx = i + l;
		arr[i + j] = array[lIdx];
		i = i + 1;
	}

	// 오른쪽만 남은 경우
	while (j < rCnt)
	{
		int rIdx = j + mid + 1;
		arr[i + j] = array[rIdx];
		j = j + 1;
	}
	
	memcpy(array + l, arr, sizeof(*arr) * (r - l +1));
	delete[] arr;
}

void Print(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 5, 4,3,2,1 };
	MergeSort(array, 0, 3);
	Print(array, 5);
}