#pragma once
#include "ICommand.h"
#include <thread>

class ThreadPool;

class Worker
{
private:
	std::thread m_thread;
	ThreadPool* m_Pool;
	void WaitForJob();
public:
	Worker(ThreadPool* pool);
	~Worker();
	void Join();
};