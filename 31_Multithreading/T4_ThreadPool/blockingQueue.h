#pragma once
#include <condition_variable>
#include "ICommand.h"
#include <mutex>
#include <thread>
#include <vector>
#include <queue>

template <typename T>
class BlockingQueue
{
private:
	std::queue<T> m_Data;
	std::mutex m_mtxData;
	std::condition_variable m_Cv;
public:

	void push(const T data)
	{
		std::unique_lock<std::mutex> lock(m_mtxData);
		m_Data.push(data);
		m_Cv.notify_one();
	}

	void pop()
	{
		std::unique_lock<std::mutex> lock(m_mtxData);
		if (!m_Data.empty())
		{
			m_Data.pop();
		}
	}

	T& front()
	{
		std::unique_lock<std::mutex> lock(m_mtxData);
		m_Cv.wait(lock, [&] { return !m_Data.empty();  });
		T& data = m_Data.front();
		return data;
	}

	T& back()
	{
		std::unique_lock<std::mutex> lock(m_mtxData);
		m_Cv.wait(lock, [&] { return !m_Data.empty();  });
		T& data = m_Data.back();
		return data;
	}

	bool empty()
	{
		return m_Data.empty();
	}
};