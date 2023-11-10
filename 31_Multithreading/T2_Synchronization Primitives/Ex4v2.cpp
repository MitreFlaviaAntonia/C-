#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <random>
#include <algorithm>

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

int binarySearch(const std::vector<int>& arr, int target, std::atomic<bool>& elementFound, int& index)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right && !elementFound)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
		{
			elementFound = true; // Set the flag to stop other threads
			index = mid;
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

int main()
{
	std::vector<int> arr = generateUniqueArray(200000, 0, 214740);
	std::sort(arr.begin(), arr.end());
	int size = arr.size();

	int target = arr[450];

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	std::atomic<bool> elementFound(false); // Flag to indicate if element is found
	int index = -1; // Index where the element was found

	// Perform single-threaded search
	index = binarySearch(arr, target, elementFound, index);

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

	// Perform multi-threaded search
	int numThreads = 11;
	int chunkSize = size / numThreads;
	elementFound = false;
	index = -1;

	start = std::chrono::high_resolution_clock::now();  // Start the timer

	std::vector<std::thread> threads;

	for (int i = 0; i < numThreads; ++i)
	{
		int threadStart = i * chunkSize;
		int threadEnd = (i == numThreads - 1) ? size : (i + 1) * chunkSize;

		threads.emplace_back(binarySearch, std::ref(arr), target, std::ref(elementFound), std::ref(index));
	}

	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}

	end = std::chrono::high_resolution_clock::now();  // Stop the timer
	duration = end - start;  // Calculate the duration

	std::cout << "Time taken (multi-threaded): " << duration.count() << " milliseconds" << std::endl;

	if (index != -1)
	{
		std::cout << "Element found at index " << index << std::endl;
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}

	return 0;
}
//0.0012 vs 6.6406