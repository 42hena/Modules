#include "StackArrayTest.h"
#include "StackListTest.h"

/**
    @def   ARRAY
    @brief ARRAY인 경우에는 StackArrayTest 테스트 코드, 
    아닌 경우에는 StackListTest 테스트 코드 실행
**/
#define ARRAY

int main()
{
#ifdef ARRAY
	// 스택 Array 테스트
	StackArrayTest();
#else
	// 스택 연결리스트 테스트
	StackListTest();
#endif
}
