#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;

void QuickSort(int array[], int l, int r)
{
    if (l >= r)
        return;

    int pivot = array[r];
    int i = l;
    int j = r;

    while (true)
    {
        // 왼쪽에서 pivot보다 큰 값 찾기
        while (i < j) {
            if (pivot < array[i])
                break;
            i = i + 1;
        }

        // 오른쪽에서 pivot보다 작은 값 찾기
        while (i < j) {
            if (pivot > array[j])
                break;
            j = j - 1;
        }
        if (i >= j)
        {
            // i와 j가 교차하면 partition 종료
            break;
        }

        swap(array[i], array[j]);
    }

    printf("prev\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");

    printf("%d %d\n", r, i);
    swap(array[r], array[j]);

    printf("After\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");

    // 재귀 호출
    QuickSort(array, l, j - 1);
    QuickSort(array, j + 1, r);
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
	int array[] = { 3, 3, 3, 3, 3 };
	int legnth = sizeof(array) / sizeof(array[0]);
	QuickSort(array, 0, legnth - 1);
	Print(array, legnth);
}
