#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

int findMin(const std::vector<int>& arr, int start, int end)
{
	int minVal = arr[start];
	for (int i = start + 1; i < end; ++i)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}
	return minVal;
}

int findMinThreads(const std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = size / numThreads;

	std::vector<int> mins(numThreads); //the vector that holds the mins from every thread
	std::vector<std::thread> threads(numThreads);

	for (int i = 0; i < numThreads; ++i)
	{
		int start = i * chunkSize;
		int end = start + chunkSize;
		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, &mins, i, start, end]()	{mins[i] = findMin(arr, start, end);});
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	int minVal = mins[0];
	for (int i = 1; i < numThreads; ++i)
	{
		if (mins[i] < minVal)
		{
			minVal = mins[i];
		}
	}

	return minVal;
}

int findMax(const std::vector<int>& arr, int start, int end)
{
	int maxVal = arr[start];
	for (int i = start + 1; i < end; ++i)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}
	return maxVal;
}

int findMaxThreads(const std::vector<int>& arr, int numThreads)
{
	int size = arr.size();
	int chunkSize = size / numThreads;

	std::vector<int> maxs(numThreads);
	std::vector<std::thread> threads(numThreads);

	for (int i = 0; i < numThreads; ++i)
	{
		int start = i * chunkSize;
		int end = start + chunkSize;
		if (i == numThreads - 1)
		{
			end = size;
		}
		threads[i] = std::thread([&arr, &maxs, i, start, end]() {maxs[i] = findMax(arr, start, end); });
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	int maxVal = maxs[0];
	for (int i = 1; i < numThreads; ++i)
	{
		if (maxs[i] > maxVal)
		{
			maxVal = maxs[i];
		}
	}

	return maxVal;
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
	std::vector<int> arr = generateRandomArray(3000000, 5, 4533000);
	int numThreads = 11;

//min
	auto start = std::chrono::high_resolution_clock::now();
	int minVal = findMinThreads(arr, numThreads);
	std::cout << "Minimum value: " << minVal << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	minVal = findMin(arr, 0, arr.size());
	std::cout << "Minimum value: " << minVal << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

//max
	start = std::chrono::high_resolution_clock::now();
	int maxVal = findMaxThreads(arr, numThreads);
	std::cout << "Maximum value: " << maxVal << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;


	start = std::chrono::high_resolution_clock::now();
	maxVal = findMax(arr, 0, arr.size());
	std::cout << "Maximum value: " << maxVal << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	return 0;
}
// min 8.4551 vs 13.9041
// max 8.0552 vs 13.6004
