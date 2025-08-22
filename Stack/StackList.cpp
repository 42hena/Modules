#include "StackList.h"

#include <memory>

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
    while (_pHead != nullptr)
    {
        StackNode* deleteNode = _pHead;
        _pHead = _pHead->_pNext;
        delete deleteNode;
    }
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

bool	StackList::Top(int& outData)
{
    return Peek(outData);
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

    return pNewNode;
}
