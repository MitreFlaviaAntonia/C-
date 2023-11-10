#include "threadPool.h"
#include "worker.h"

ThreadPool::ThreadPool(int size) : m_nSize(size)
{
}

void ThreadPool::Start()
{
	for (int i = 0; i < m_nSize; ++i)
	{
		Worker* pWorker = new Worker(this);
		m_Workers.push_back(pWorker);
	}
	m_bRunning = true;
}

void ThreadPool::ShutDown()
{
	{
		std::unique_lock<std::mutex> lock(mtxThreadStatus);
		m_bRunning = false;
	}
	m_Cv.notify_all();
	for (Worker* worker : m_Workers)
	{
		worker->Join();
		delete worker;
	}
	m_Workers.clear();
}

bool ThreadPool::Running()
{
	return m_bRunning;
}

BlockingQueue<ICommand*>& ThreadPool::GetQueue()
{
	return m_Jobs;
}

void ThreadPool::Enqueue(ICommand* cmd)
{
	mtxThreadJob.lock();
	m_Jobs.push(cmd);
	mtxThreadJob.unlock();
	m_Cv.notify_one();
}