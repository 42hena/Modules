#include "Logger.h"

#include <iostream>
#include <Windows.h>

LoggerManager* LoggerManager::_static_pLoggerManager = nullptr;

LoggerManager::LoggerManager()
{
	_logThread = std::thread(ProcessLogThread);
}

LoggerManager::~LoggerManager()
{
	if (_logThread.joinable())
		_logThread.join();
}

/*
*		static ÇÔ¼ö
*/

void LoggerManager::EnqueueLog(std::wstring str)
{
	std::lock_guard<std::mutex> lock(_logQueueLock);
	_logQueue.push(str);
}

std::wstring LoggerManager::GetLog()
{
	std::lock_guard<std::mutex> lock(_logQueueLock);
	std::wstring log = std::move(_logQueue.front());
	_logQueue.pop();
	return log;
}

LoggerManager& LoggerManager::GetInstance()
{
	return *_static_pLoggerManager;
}

void LoggerManager::Create()
{
	_static_pLoggerManager = new  LoggerManager();
	atexit(LoggerManager::Destroy);
}

void LoggerManager::Destroy()
{
	delete _static_pLoggerManager;
}

void LoggerManager::ProcessLogThread()
{
	while (_runningFlag == true)
	{
		std::move(_logQueue.front());
		_logQueue.pop();
		Sleep(1000);
	}
}
