#ifndef __QUEUE_H__
#define __QUEUE_H__

class QueueArray
{
	static const int cArraySize = 10;
#pragma region 특수 멤버 함수
public:
	QueueArray();
	~QueueArray()								= default;
	QueueArray(const QueueArray&)				= default;
	QueueArray& operator=(const QueueArray&)	= default;
	QueueArray(QueueArray&&)					= default;
	QueueArray& operator=(QueueArray&&)			= default;
#pragma endregion

#pragma region 공개 함수
public:
	bool	Push(int data);
	bool	Pop(int& outData);
	bool	Front(int& outData);
	bool	Back(int& outData);

	bool	IsEmpty()	const;
	bool	IsFull()	const;
	int		Size()		const;
	int		BufferSize()const;

	void	Clear();
#pragma endregion

#pragma region 멤버 변수
private:
	int _data[cArraySize];
	int	_front = 0;
	int	_rear = 0;
#pragma endregion
};

struct QueueNode
{
	QueueNode*	_pNext;
	int			_data;
};

class QueueList
{
	static const int cArraySize = 10;
#pragma region 특수 멤버 함수
public:
	QueueList();
	~QueueList();
	QueueList(const QueueList&)				= delete;
	QueueList& operator=(const QueueList&)	= delete;
	QueueList(QueueList&&)					= delete;
	QueueList& operator=(QueueList&&)		= delete;
#pragma endregion

#pragma region 공개 함수
public:
	bool	Push(int data);
	bool	Pop(int& outData);
	bool	Front(int& outData);
	bool	Back(int& outData);

	bool	IsEmpty()	const;
	int		Size()		const;

#pragma endregion

#pragma region 내부 함수

private:
	QueueNode* CreateNode();
#pragma endregion

#pragma region 멤버 변수
private:
	QueueNode*	_front;
	QueueNode*	_rear;
	int			_size;
#pragma endregion
};

#endif
