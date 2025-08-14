#include "Stack.h"

#include <memory>
/*
*		
*/

StackArray::StackArray()
	:_top(0)
{
	memset(_data, 0, sizeof(_data));
}

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
