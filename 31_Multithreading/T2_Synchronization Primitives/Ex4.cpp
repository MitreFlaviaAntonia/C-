#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

std::vector<int> generateUniqueArray(int size, int min, int max)
{
	std::vector<int> array;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(min, max);

	while (array.size() < size)
	{
		int num = dis(gen);
		if (std::find(array.begin(), array.end(), num) == array.end())
		{
			array.push_back(num);
		}
	}

	return array;
}

int binarySearch(const std::vector<int>& arr, int target)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1; // Element not found
}

void binarySearchThreads(const std::vector<int>& arr, int target, int left, int right, int& result)
{
	result = binarySearch(arr, target); // Store the search result in 'result'
}

int main()
{
	std::vector<int> arr = generateUniqueArray(200000, 0, 214740);
	std::sort(arr.begin(), arr.end());
	int size = arr.size();

	int target = arr[450];

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	int index = binarySearch(arr, target);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer
	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken (single thread): " << duration.count() << " milliseconds" << std::endl;

	if (index != -1)
	{
		std::cout << "Element found at index " << index << std::endl;
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}

	int numThreads = 11;
	int chunkSize = size / numThreads;

	start = std::chrono::high_resolution_clock::now();  // Start the timer

	std::vector<std::thread> threads;
	std::vector<int> threadResults(numThreads); // Store results from threads

	for (int i = 0; i < numThreads; ++i)
	{
		int threadStart = i * chunkSize;
		int threadEnd;

		if (i == numThreads - 1)
		{
			threadEnd = size;
		}
		else
		{
			threadEnd = (i + 1) * chunkSize;
		}

		threads.emplace_back(binarySearchThreads, std::ref(arr), target, threadStart, threadEnd, std::ref(threadResults[i]));
	}

	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}

	int combinedIndex = -1; // Result to combine from threads

	for (int i = 0; i < numThreads; ++i)
	{
		if (threadResults[i] != -1)
		{
			combinedIndex = threadResults[i];
			break;
		}
	}

	end = std::chrono::high_resolution_clock::now();  // Stop the timer
	duration = end - start;  // Calculate the duration

	std::cout << "Time taken (multi-threaded): " << duration.count() << " milliseconds" << std::endl;

	if (combinedIndex != -1)
	{
		std::cout << "Element found at index " << combinedIndex << std::endl;
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}

	return 0;
}
//0.0009 vs 5.7754