#include "Logger.h"
#include <iostream>

int main()
{
	LoggerManager::Create();
	std::wcout << "endof main\n";
}