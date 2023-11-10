#pragma once
#include <functional>
#include <vector>

enum class Operation
{
	minMax, sum, squaresCubes
};

struct ICommand
{
	std::vector<int>* m_data;
	std::vector<int>* m_vecResult = nullptr;
	long* m_longResult = nullptr;
	int* m_intResult = nullptr;
	int m_start = 0;
	int m_end = 0;
	Operation m_operation;
	std::function<void(const std::vector<int>&, int, int, int&)> m_minMaxFunction;
	std::function<void(const std::vector<int>&, int, int, long&)> m_sumFunction;
	std::function<void(const std::vector<int>&, int, int, std::vector<int>&)> m_squaresCubesFunction;
	ICommand(std::function<void(const std::vector<int>&, int, int, int&)> minMaxFunction, std::vector<int>* data, int start, int end, int* result) : m_minMaxFunction(minMaxFunction), m_data(data), m_start(start)
		, m_end(end), m_intResult(result)
	{
		m_operation = Operation::minMax;
	}
	ICommand(std::function<void(const std::vector<int>&, int, int, long&)> sumFunction, std::vector<int>* data, int start, int end, long* result) : m_sumFunction(sumFunction), m_data(data), m_start(start)
		, m_end(end), m_longResult(result)
	{
		m_operation = Operation::sum;
	}
	ICommand(std::function<void(const std::vector<int>&, int, int, std::vector<int>&)> squaresCubesFunction, std::vector<int>* data, int start, int end, std::vector<int>* result)
		: m_squaresCubesFunction(squaresCubesFunction)
		, m_data(data)
		, m_start(start)
		, m_end(end)
		, m_vecResult(result)
		
	{
		m_operation = Operation::squaresCubes;
	}

	void Execute()
	{
		if (m_operation == Operation::sum)
		{
			m_sumFunction(*m_data, m_start, m_end, *m_longResult);
		}
		if (m_operation == Operation::minMax)
		{
			m_minMaxFunction(*m_data, m_start, m_end, *m_intResult);
		}
		if (m_operation == Operation::squaresCubes)
		{
			m_squaresCubesFunction(*m_data, m_start, m_end, *m_vecResult);
		}
	}
};