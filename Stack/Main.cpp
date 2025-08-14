#include "Stack.h"
#include <stack>
#include <iostream>

void StackArrayTest()
{
	StackArray sa;
	for (int i = 0; i < 11; ++i) {
		bool retPush = sa.Push(i + 1);
		printf("Push 성공 여부: %d, 삽입 값: %d\n", retPush, i + 1);
	}

	printf("\n");
	printf("Empty      : %d\n", sa.IsEmpty());
	printf("Full       : %d\n", sa.IsFull());
	printf("Size       : %d\n", sa.Size());
	printf("BufferSize : %d\n\n", sa.BufferSize());


	int peekValue, popValue;
	int Size = sa.Size();
	for (int i = 0; i < Size + 1; ++i) {
		bool retPeek = sa.Peek(peekValue);
		bool retPop = sa.Pop(popValue);

		printf("Peek 성공 여부: %d, 값: %d\n", retPeek, peekValue);
		printf("Pop  성공 여부: %d, 값: %d\n\n", retPop, popValue);
	}

	printf("\n");
	printf("Empty      : %d\n", sa.IsEmpty());
	printf("Full       : %d\n", sa.IsFull());
	printf("Size       : %d\n", sa.Size());
	printf("BufferSize : %d\n\n", sa.BufferSize());
}

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

int main()
{
#ifdef ARRAY
	// 스택 Array 테스트
	StackArrayTest();
#else
	// 스택 연결리스트 테스트
	StackListTest();
#endif
}
