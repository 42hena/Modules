#ifndef __STACK_H__
#define __STACK_H__

class StackArray
{
	static const int cArraySize = 10;
public:
	StackArray();
	~StackArray()								= default;
	StackArray(const StackArray&)				= default;
	StackArray& operator=(const StackArray&)	= default;
	StackArray(StackArray&&)					= default;
	StackArray& operator=(StackArray&&)			= default;

public:
	bool	Push(int data);
	bool	Pop(int& outData);
	bool	Peek(int& outData);

	bool	IsEmpty()	const;
	bool	IsFull()	const;
	int		Size()		const;
	int		BufferSize()const;

private:
	int _data[cArraySize];
	int	_top = 0;
};

#endif
