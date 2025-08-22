#include "StackListTest.h"
#include "StackList.h"

#include <iostream>

void StackListTest()
{
    StackList sl;
    for (int i = 0; i < 11; ++i) {
        bool retPush = sl.Push(i + 1);
        printf("Push 성공 여부: %d, 삽입 값: %d\n", retPush, i + 1);
    }

    printf("\n");
    printf("Empty      : %d\n", sl.IsEmpty());
    printf("Size       : %d\n\n", sl.Size());


    int peekValue, popValue;
    int Size = sl.Size();
    for (int i = 0; i < Size + 1; ++i) {
        bool retPeek = sl.Peek(peekValue);
        bool retPop = sl.Pop(popValue);

        printf("Peek 성공 여부: %d, 값: %d\n", retPeek, peekValue);
        printf("Pop  성공 여부: %d, 값: %d\n\n", retPop, popValue);
    }

    printf("\n");
    printf("Empty      : %d\n", sl.IsEmpty());
    printf("Size       : %d\n", sl.Size());
}

