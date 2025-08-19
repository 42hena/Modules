#include "QuickSort.h"
#include <iostream>

int Partition(int array[], int left, int right)
{
    int pivotIdx = left;
    int pivotValue = array[left];
    int i = left + 1;
    int j = right;

    while (true)
    {
        // 왼쪽에서 pivot보다 큰 값 찾기
        while (i <= j) {
            if (pivotValue < array[i])
                break;
            i = i + 1;
        }

        // 오른쪽에서 pivot보다 작은 값 찾기
        while (i <= j) {
            if (pivotValue > array[j])
                break;
            j = j - 1;
        }

        // i와 j가 교차하면 partition 종료
        if (i > j) {
            break;
        }

        Swap(array[i], array[j]);
    }

    // pivotIdx의 위치와 j의 위치를 변환 시킴.
    Swap(array[pivotIdx], array[j]);

    return j;
}

void QuickSort(int* array, int left, int right)
{
    // 배열의 값이 한 개일 경우
    if (left >= right) {
        return;
    }

    // 피벗을 기준으로 배열 분할
    int pivotIdx = Partition(array, left, right);

    // 왼쪽 배열 정렬
    QuickSort(array, left, pivotIdx - 1);

    // 오른쪽 배열 정렬
    QuickSort(array, pivotIdx + 1, right);
}

void Print(int array[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
