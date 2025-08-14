#include "Stack.h"

#include <memory>

/*
*		특수 멤버 함수
*/

StackArray::StackArray()
	:_top(0)
{
	memset(_data, 0, sizeof(_data));
}

/*
*		메시지 함수
*/

bool StackArray::Push(int data)
{
	// Case 스택이 꽉찬 경우
	if (IsFull()) {
		return false;
	}
	
	// 데이터 삽입 및 _top 인덱스 증가
	_data[_top] = data;
	_top = _top + 1;
	return true;
}

bool StackArray::Pop(int& outData)
{
	// Case Peek 실패 시
	if (Peek(outData) == false) {
		return false;
	}

	_top = _top - 1;
	return true;
}

bool StackArray::Peek(int& outData)
{
	// Case 스택이 빈 경우
	if (IsEmpty()) {
		return false;
	}

	// 데이터 값 확인
	outData = _data[_top - 1];
	return true;
}

bool StackArray::IsEmpty() const
{
	// Case _top이 0인 경우(빔)
	if (_top == 0) {
		return true;
	}
	// Case 존재하는 경우(스택 내부에 값이 존재.
	return false;
}

bool StackArray::IsFull() const
{
	// Case _top이 최대치인 경우인 경우(빔)
	if (_top >= cArraySize) {
		return true;
	}
	// Case 존재하는 경우(스택 내부에 값이 존재.
	return false;
}

int	StackArray::Size() const
{
	return _top;
}

int	StackArray::BufferSize() const
{
	return cArraySize;
}

void StackArray::Clear()
{
	_top = 0;
}

/*
*		StackList의 특수 멤버 함수
*/

StackList::StackList()
	:_pHead(nullptr),
	_size(0)
{
}

StackList::~StackList()
{
}

/*
*		StackList의 메시지 함수
*/

bool	StackList::Push(int data)
{
	StackNode* newHeadNode = CreateNewNode();
	
	// 노드 데이터 초기화
	newHeadNode->_data = data;
	newHeadNode->_pNext = _pHead;
	
	// head 옮기기 및 노드 카운트 증가
	_pHead = newHeadNode;
	_size = _size + 1;

	
	return true;
}

bool	StackList::Pop(int& outData)
{
	// Case 스택이빔
	if (Peek(outData) == false) {
		return false;
	}

	StackNode* deleteNode = _pHead;


	// head 옮기기 및 노드 카운트 감소
	_size = _size - 1;
	_pHead = _pHead->_pNext;
	
	// 다쓴 노드 삭제
	delete deleteNode;

	return true;
}

bool	StackList::Peek(int& outData)
{
	if (IsEmpty()) {
		return false;
	}

	// 데이터 대입
	outData = _pHead->_data;
	
	return true;
}

bool	StackList::IsEmpty() const
{
	return _size == 0;	// head가 nullptr로 판단 가능.
}

int		StackList::Size() const
{
	return _size;
}

/*
*		StackList의 내부 함수
*/

StackNode* StackList::CreateNewNode()
{
	// 노드 생성 및 초기화
	StackNode* pNewNode = new StackNode();
	pNewNode->_pNext = nullptr;

	return pNewNode;
}
