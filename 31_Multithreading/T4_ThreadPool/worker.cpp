#include "threadPool.h"
#include "worker.h"

void Worker::WaitForJob()
{
	while (m_Pool->Running())
	{
		ICommand* job = nullptr;
		if (!m_Pool->GetQueue().empty())
		{
			job = m_Pool->GetQueue().front();
			m_Pool->GetQueue().pop();
		}
		if (job)
		{
			job->Execute();
			m_Pool->mtxThreadFinish.lock();
			m_Pool->ReportFinished();
			m_Pool->mtxThreadFinish.unlock();
		}
	}
}

Worker::Worker(ThreadPool* pool) : m_Pool(pool)
{
	m_thread = std::thread(&Worker::WaitForJob, this);
}

Worker::~Worker()
{
	if (m_thread.joinable())
	{
		m_thread.join();
	}
}

void Worker::Join()
{
	m_thread.join();
}