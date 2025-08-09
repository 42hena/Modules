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
	static void Create();	// friend 사용해서 특정 클래스에서만 사용.
	static void Destroy();	// friend 사용해서 특정 클래스에서만 사용.

private:
	std::wstring GetLog();

private:	/* 쓰레드 함수 */
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
