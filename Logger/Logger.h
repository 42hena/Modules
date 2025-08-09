#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdlib.h>
#include <queue>
#include <string>
#include <mutex>

//class Logger {
//public:
//
//private:
//
//};

class LoggerManager {
private:
	LoggerManager();
	~LoggerManager();

public:
	LoggerManager(const LoggerManager&)				= delete;
	LoggerManager(LoggerManager&&)					= delete;
	LoggerManager& operator=(const LoggerManager&)	= delete;
	LoggerManager& operator=(LoggerManager&&)		= delete;

public:
	void EnqueueLog(std::wstring str);
private:
	std::wstring Log();

public:
	static LoggerManager& GetInstance();

private:
	static void Create();	// friend ����ؼ� Ư�� Ŭ���������� ���.
	static void Destroy();	// friend ����ؼ� Ư�� Ŭ���������� ���.

private:
	std::wstring GetLog();

private:	/* ������ �Լ� */
	void ProcessLogThread();
	

private:
	static LoggerManager*		_static_pLoggerManager;

private:
	bool						_runningFlag = false;
	std::queue<std::wstring>	_logQueue;
	std::mutex					_logQueueLock;

	std::thread					_logThread;
};

#endif
