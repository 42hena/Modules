#include "Queue.h"
#include <iostream>

void QueueArrayTest()
{
	QueueArray qa;

	for (int i = 0; i < 10; ++i)
	{
		bool retPush = qa.Push(i + 1);
		printf("Push 성공 여부: %d, 삽입 값: %d\n", retPush, i + 1);
	}

	printf("\n");
	printf("Empty      : %d\n", qa.IsEmpty());
	printf("Full       : %d\n", qa.IsFull());
	printf("Size       : %d\n", qa.Size());
	printf("BufferSize : %d\n\n", qa.BufferSize());

	int frontValue;
	int popValue;
	int Size = qa.Size();
	for (int i = 0; i < Size + 1; ++i) {
		bool retFront = qa.Front(frontValue);
		bool retPop = qa.Pop(popValue);

		printf("Peek 성공 여부: %d, 값: %d\n", retFront, frontValue);
		printf("Pop  성공 여부: %d, 값: %d\n\n", retPop, popValue);
	}

	printf("\n");
	printf("Empty      : %d\n", qa.IsEmpty());
	printf("Full       : %d\n", qa.IsFull());
	printf("Size       : %d\n", qa.Size());
	printf("BufferSize : %d\n\n", qa.BufferSize());
}

void QueueListTest()
{
	QueueList ql;

	for (int i = 0; i < 10; ++i)
	{
		bool retPush = ql.Push(i + 1);
		printf("Push 성공 여부: %d, 삽입 값: %d\n", retPush, i + 1);
	}

	printf("\n");
	printf("Empty      : %d\n", ql.IsEmpty());
	printf("Size       : %d\n\n", ql.Size());

	int frontValue;
	int popValue;
	int Size = ql.Size();
	for (int i = 0; i < Size + 1; ++i) {
		bool retFront = ql.Front(frontValue);
		bool retPop = ql.Pop(popValue);

		printf("Peek 성공 여부: %d, 값: %d\n", retFront, frontValue);
		printf("Pop  성공 여부: %d, 값: %d\n\n", retPop, popValue);
	}

	printf("\n");
	printf("Empty      : %d\n", ql.IsEmpty());
	printf("Size       : %d\n\n", ql.Size());
}

int main()
{
#ifdef ARRAY
	// 큐 Array 테스트
	QueueArrayTest();
#else
	// 큐 연결리스트 테스트
	QueueListTest();
#endif
}
