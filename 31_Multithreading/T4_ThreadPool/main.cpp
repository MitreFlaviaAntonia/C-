#include "ThreadPool.h"
#include "ICommand.h"
#include "BlockingQueue.h"
#include "Worker.h"
#include <functional>
#include <iostream>
#include <vector>
#include "functions.h"
#include <chrono>

std::vector<int> GenerateNumbers(int n)
{
	std::vector<int> numbers;
	numbers.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		numbers.push_back(1 + rand() % 10);
	}
	return numbers;
}

int main()
{
	ThreadPool pool(3);
	std::vector<int> numbers = GenerateNumbers(10);
	int max = INT_MIN;
	int min = INT_MAX;
	std::vector<int> squaredNumbers(numbers.size(), -1);
	std::vector<int> cubedNumbers(numbers.size(), -1);
	long squaredSum = 0;
	long cubedSum = 0;
	std::vector<ICommand> commands;

	commands.emplace_back(std::function(findMax), &numbers, 0, static_cast<long>(numbers.size()), &max);
	commands.emplace_back(std::function(findMin), &numbers, 0, static_cast<long>(numbers.size()), &min);
	commands.emplace_back(std::function(calculateSquares), &numbers, 0, static_cast<long>(numbers.size()), &squaredNumbers);
	commands.emplace_back(std::function(calculateCubes), &numbers, 0, static_cast<long>(numbers.size()), &cubedNumbers);
	pool.Start();
	for (auto& c : commands)
	{
		pool.Enqueue(&c);
	}
	while (pool.JobsFinished() < 4)
	{
	}
	commands.clear();
	commands.emplace_back(std::function(calculateSum), &squaredNumbers, 0, static_cast<long>(numbers.size()), &squaredSum);
	commands.emplace_back(std::function(calculateSum), &cubedNumbers, 0, static_cast<long>(numbers.size()), &cubedSum);
	for (auto& c : commands)
	{
		pool.Enqueue(&c);
	}

	while (pool.JobsFinished() < 6)
	{
	}
	pool.ShutDown();
	std::cout << "\nNumbers: ";
	for (int x : numbers)
	{
		std::cout << x << ' ';
	}
	std::cout << "\nMin: " << min << ", Max: " << max;
	std::cout << "\nSquared: ";
	for (int x : squaredNumbers)
	{
		std::cout << x << ' ';
	}
	std::cout << "\nSum of squares: " << squaredSum;
	std::cout << "\nCubed: ";
	for (int x : cubedNumbers)
	{
		std::cout << x << ' ';
	}
	std::cout << "\nSum of cubes: " << cubedSum;
	return 0;
}