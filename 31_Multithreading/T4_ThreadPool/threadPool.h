#pragma once
#include "blockingQueue.h"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include "worker.h"

class ThreadPool
{
private:
	std::vector<Worker*> m_Workers;
	BlockingQueue<ICommand*> m_Jobs;
	volatile bool m_bRunning = false;
	std::mutex mtxThreadStatus;
	std::mutex mtxThreadJob;
	std::mutex mtxThreadFinish;
	int m_nSize;
	int m_jobsFinished = 0;
	std::condition_variable m_Cv;
	friend class Worker;
	void ReportFinished()
	{
		++m_jobsFinished;
	}
public:
	ThreadPool(int size);
	void Start();
	void ShutDown();
	bool Running();
	BlockingQueue<ICommand*>& GetQueue();
	void Enqueue(ICommand* cmd);
	int JobsFinished()
	{
		return m_jobsFinished;
	}
};