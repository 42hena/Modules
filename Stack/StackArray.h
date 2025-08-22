#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__

/*
*		배열로 구현한 스택
*/

#define STACK_ARRAY_BUFFER_SIZE 100

/**

    @class   StackArray
    @brief   스택을 배열로 구현한 함수
    @details ~

**/
class StackArray
{
    static const int cArraySize = STACK_ARRAY_BUFFER_SIZE;
#pragma region 특수 멤버 함수
public:
    StackArray();
    ~StackArray()                           = default;

    StackArray(const StackArray&)           = default;
    StackArray(StackArray&&)                = default;

    StackArray& operator=(const StackArray&)= default;
    StackArray& operator=(StackArray&&)     = default;
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
    bool	Peek(int& outData); // Top과 동일
    bool	Top(int& outData);


    /**
        @brief  스택 내부가 비었는지 확인하는 함수
        @retval  - 비었는지 여부
    **/
    bool	IsEmpty()	const;

    /**
        @brief  스택 내부가 꽉 찼는지 확인하는 함수
        @retval  - 꽉 찼는지 여부
    **/
    bool	IsFull()	const;

    /**
        @brief  스택 내부의 원소들의 개수를 확인하는 함수
        @retval  - 스택 내부 원소의 개수
    **/
    int		Size()		const;

    /**
        @brief  스택이 저장할 수 있는 최대 사이즈를 알려주는 함수
        @retval  - 버퍼 최대 사이즈
    **/
    int		BufferSize()const;

    /**
        @brief 스택을 생성 초기 상태로 되돌리는 함수
    **/



    void	Clear();
#pragma endregion

#pragma region 멤버 변수


private:
    int _data[cArraySize];
    int	_top = 0;
#pragma endregion
};

#endif
