#include "Queue.h"

#include <memory>

/*
*		Queue Array의 특수 멤버 함수
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

/*
*		Queue List의 특수 멤버 함수
*/

QueueList::QueueList()
	:_rear(nullptr),
	_front(nullptr),
	_size(0)
{
	QueueNode* dummy = new QueueNode();
	_front = dummy;
	_rear = dummy;
}

QueueList::~QueueList()
{
	while (_front != _rear) {
		QueueNode* deleteNode = _front;
		_front = _front->_pNext;
		delete deleteNode;
	}
	delete _front;
}

/*
*		메시지 함수
*/

bool QueueList::Push(int data)
{
	// 데이터 삽입 및 _rear 포인트 이동
	QueueNode* newRearNode = new QueueNode();
	newRearNode->_data = data;
	_rear->_pNext = newRearNode;

	_rear = newRearNode;
	_size = _size + 1;
	return true;
}

bool QueueList::Pop(int& outData)
{
	// Front가 실패한 경우
	if (Front(outData) == false) {
		return false;
	}

	// front 포인터 이동 및 size 감소 
	_front = _front->_pNext;
	_size = _size - 1;
	return true;
}

bool QueueList::Front(int& outData)
{
	// 큐가 빈 경우
	if (IsEmpty() == true) {
		return false;
	}

	// 데이터 추출
	outData = _front->_pNext->_data;
	return true;
}

bool QueueList::IsEmpty() const
{
	return _front == _rear;
}

int	QueueList::Size() const
{
	return _size;
}

/*
*		내부 함수
*/

QueueNode* QueueList::CreateNode()
{
	QueueNode* newNode = new QueueNode();
	newNode->_pNext = nullptr;

	return newNode;
}
