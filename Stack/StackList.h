#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__

/*
*		연결리스트로 구현한 스택
*/

/**
    @struct StackNode
    @brief  StackList에서 사용할 노드 구조체
**/
struct StackNode
{
    int			_data;
    StackNode* _pNext = nullptr;
};

/**

    @class   StackList
    @brief   리스트로 구현한 스택 객체
    @details ~

**/
class StackList
{
#pragma region 특수 멤버 함수
public:
    StackList();
    ~StackList();

    StackList(const StackList&) = delete;
    StackList(StackList&&) = delete;

    StackList& operator=(const StackList&) = delete;
    StackList& operator=(StackList&&) = delete;
#pragma endregion

#pragma region 공개 함수
public:
    /**
        @brief  스택에 마지막 원소 뒤에 추가하는 함수
        @param  data - 삽입할 데이터
        @retval      - 성공 실패 여부
    **/
    bool	Push(int data);

    /**
        @brief  스택의 마지막 원소를 제거하고 제거한 데이터를 반환하는 함수
        @param  outData - 제거한 원소 데이터
        @retval         - 성공 실패 여부
    **/
    bool	Pop(int& outData);

    /**
        @brief  마지막 원소의 데이터 값을 확인
        @param  outData - 마지막 원소 데이터
        @retval         - 성공 실패 여부
    **/
    bool	Peek(int& outData);
    bool	Top(int& outData);

    /**
        @brief  스택 내부가 꽉 찼는지 확인하는 함수
        @retval  - 꽉 찼는지 여부
    **/
    bool	IsEmpty()	const;

    /**
        @brief  스택 내부의 원소들의 개수를 확인하는 함수
        @retval  - 스택 내부 원소의 개수
    **/
    int		Size()		const;
#pragma endregion

#pragma region 개인 함수
private:

    /**
        @brief  
        @retval  - 새로운 스택 노드 반환
    **/
    StackNode* CreateNewNode();
#pragma endregion

#pragma region 멤버 변수
private:
    StackNode*  _pHead;
    int			_size = 0;
#pragma endregion
};

#endif
