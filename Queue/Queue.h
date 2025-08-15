#pragma once

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