#ifndef __STACK_H__
#define __STACK_H__

/*
*		배열로 구현한 스택
*/

class StackArray
{
	static const int cArraySize = 10;
#pragma region 특수 멤버 함수
public:
	StackArray();
	~StackArray()								= default;
	StackArray(const StackArray&)				= default;
	StackArray& operator=(const StackArray&)	= default;
	StackArray(StackArray&&)					= default;
	StackArray& operator=(StackArray&&)			= default;
#pragma endregion

#pragma region 공개 함수
public:
	bool	Push(int data);
	bool	Pop(int& outData);
	bool	Peek(int& outData);

	bool	IsEmpty()	const;
	bool	IsFull()	const;
	int		Size()		const;
	int		BufferSize()const;

	void	Clear();
#pragma endregion

#pragma region 멤버 변수
private:
	int _data[cArraySize];
	int	_top = 0;
#pragma endregion
};

/*
*		연결리스트로 구현한 스택
*/

// 연결리스트에서 사용할 구조체
struct StackNode
{
	int			_data;
	StackNode*	_pNext = nullptr;
};

class StackList
{
#pragma region 특수 멤버 함수
public:
	StackList();
	~StackList();
	StackList(const StackList&)				= delete;
	StackList& operator=(const StackList&)	= delete;
	StackList(StackList&&)					= delete;
	StackList& operator=(StackList&&)		= delete;
#pragma endregion

#pragma region 공개 함수
public:
	bool	Push(int data);
	bool	Pop(int& outData);
	bool	Peek(int& outData);

	bool	IsEmpty()	const;
	int		Size()		const;
#pragma endregion

#pragma region 개인 함수
private:
	StackNode* CreateNewNode();
#pragma endregion

#pragma region 멤버 변수
private:
	StackNode*	_pHead;
	int			_size = 0;
#pragma endregion
};

#endif
