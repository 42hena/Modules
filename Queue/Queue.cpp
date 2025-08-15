#include "Queue.h"

#include <memory>

/*
*		특수 멤버 함수
*/

QueueArray::QueueArray()
	:_rear(0),
	_front(0)
{
	memset(_data, 0, sizeof(_data));
}

/*
*		메시지 함수
*/

bool QueueArray::Push(int data)
{
	// Case 큐가 꽉찬 경우
	if (IsFull()) {
		return false;
	}

	// 데이터 삽입 및 _rear 인덱스 증가
	_data[_rear] = data;
	_rear = (_rear + 1) % cArraySize;
	return true;
}

bool QueueArray::Pop(int& outData)
{
	// Front가 실패한 경우
	if (Front(outData) == false) {
		return false;
	}

	// front 인덱스 증가
	_front = (_front + 1) % cArraySize;
	return true;
}

bool QueueArray::Front(int& outData)
{
	// 큐가 빈 경우
	if (IsEmpty() == true) {
		return false;
	}

	// 데이터 추출
	outData = _data[_front];

	return true;
}

bool QueueArray::IsEmpty() const
{
	return _front == _rear;
}

bool QueueArray::IsFull() const
{
	return (_rear + 1) % cArraySize == _front;
}

int	QueueArray::Size() const
{
	if (_front <= _rear)
		return _rear - _front;
	return _rear + cArraySize - _front - 1;
}

int	QueueArray::BufferSize() const
{
	return cArraySize;
}

void QueueArray::Clear()
{
	_front = 0;
	_rear = 0;
}
