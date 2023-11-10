#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <mutex>
#include <cmath>

std::mutex myMutex;
std::vector<long long int> squaresSums(11, 0);
std::vector<long long int> cubesSums(11, 0);

void calculateSquares(std::vector<int>& arr, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		std::lock_guard<std::mutex> guard(myMutex);
		arr[i] = pow(arr[i], 2);
	}
}

void calculateSquaresSum(const std::vector<int>& arr, int start, int end, int index)
{
	for (int i = start; i < end; ++i)
	{
		std::lock_guard<std::mutex> guard(myMutex);
		squaresSums[index] = squaresSums[index] + arr[i];
	}
}

void calculateSquaresThreads(std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = std::round(static_cast<double>(size) / numThreads);
	std::vector<std::thread> threads(numThreads);

	int start;
	int end = 0;
	for (int i = 0; i < numThreads || end < size; ++i)
	{
		start = i * chunkSize;
		end = start + chunkSize;

		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, start, end]() {calculateSquares(arr, start, end); });
	}

	for (auto& thread : threads)
	{
		thread.join();
	}
}

int calculateSquaresSumThreads(const std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = size / numThreads;


	std::vector<std::thread> threads(numThreads);

	for (int i = 0; i < numThreads; ++i)
	{
		int start = i * chunkSize;
		int end = start + chunkSize;
		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, start, end, i]() {calculateSquaresSum(arr, start, end, i); });
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	long long int finalSum = 0;
	for (int i = 0; i < numThreads; ++i)
	{
		finalSum = finalSum + squaresSums[i];
	}

	return finalSum;
}


void calculateCubes(std::vector<int>& arr, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		std::lock_guard<std::mutex> guard(myMutex);
		arr[i] = pow(arr[i], 3);
	}
}

void calculateCubesSum(const std::vector<int>& arr, int start, int end, int index)
{
	for (int i = start; i < end; ++i)
	{
		std::lock_guard<std::mutex> guard(myMutex);
		cubesSums[index] = cubesSums[index] + arr[i];
	}
}

void calculateCubesThreads(std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = std::round(static_cast<double>(size) / numThreads);
	std::vector<std::thread> threads(numThreads);

	int start;
	int end = 0;
	for (int i = 0; i < numThreads || end < size; ++i)
	{
		start = i * chunkSize;
		end = start + chunkSize;

		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, start, end]() {calculateCubes(arr, start, end); });
	}

	for (auto& thread : threads)
	{
		thread.join();
	}
}

int calculateCubesSumThreads(const std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = size / numThreads;

	std::vector<std::thread> threads(numThreads);

	for (int i = 0; i < numThreads; ++i)
	{
		int start = i * chunkSize;
		int end = start + chunkSize;
		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, start, end, i]() {calculateCubesSum(arr, start, end, i); });
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	long long int finalSum = 0;
	for (int i = 0; i < numThreads; ++i)
	{
		finalSum = finalSum + cubesSums[i];
	}

	return finalSum;
}

std::vector<int> generateRandomArray(int size, int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(min, max);

	std::vector<int> arr(size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = dis(gen);
	}

	return arr;
}

int main()
{

	std::vector<int> arr = generateRandomArray(10000, 5, 10);
	std::vector<int> arr2 = arr;
	std::vector<int> arr3 = arr;
	std::vector<int> arr4 = arr;

	int numThreads = 11;
	/*for (int num : arr)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;*/


	auto start = std::chrono::high_resolution_clock::now();
	calculateSquaresThreads(arr, numThreads);
	for (int num : arr)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	std::cout << "Squares with threads: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	calculateSquares(arr2, 0, arr2.size());
	for (int num : arr2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Squares simple: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	long long int sum = calculateSquaresSumThreads(arr, numThreads);
	std::cout << "Sum value: " << sum << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken with threads: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	squaresSums[0] = 0;
	calculateSquaresSum(arr2, 0, arr2.size(), 0);
	std::cout << "Sum value: " << squaresSums[0] << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken simple: " << duration.count() << " milliseconds" << std::endl;


	//cubes
	start = std::chrono::high_resolution_clock::now();
	calculateCubesThreads(arr3, numThreads);
	for (int num : arr3)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Cubes with threads: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	calculateCubes(arr4, 0, arr4.size());
	for (int num : arr4)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Cubes simple: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	sum = 0;
	sum = calculateCubesSumThreads(arr3, numThreads);
	std::cout << "Sum value: " << sum << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken with threads: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	cubesSums[0] = 0;
	calculateCubesSum(arr4, 0, arr4.size(), 0);
	std::cout << "Sum value: " << cubesSums[0] << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken simple: " << duration.count() << " milliseconds" << std::endl;

	return 0;
}