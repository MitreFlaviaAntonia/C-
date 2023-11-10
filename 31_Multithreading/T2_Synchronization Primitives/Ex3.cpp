#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>

void compare(std::vector<int>& arr, int a, int b, bool &isSorted)
{
	if (arr[a] > arr[b])
	{
		std::swap(arr[a], arr[b]);
		isSorted = false;
	}
}

// A function to sort the algorithm using Odd Even sort
void oddEvenSortThreads(std::vector<int>& arr, int n)
{
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed elements
		for (int i = 1; i <= n - 2; i = i + 2)
		{
			std::thread threadOdd([&]() {compare(arr, i, i + 1, isSorted); });
			threadOdd.join();
		}

		// Perform Bubble sort on even indexed elements
		for (int i = 0; i <= n - 2; i = i + 2)
		{
			std::thread threadEven([&]() {compare(arr, i, i + 1, isSorted); });
			threadEven.join();
		}
	}
}

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(std::vector<int>& arr, int n)
{
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed elements
		for (int i = 1; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed elements
		for (int i = 0; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}
}

void oddEvenSortChunk(std::vector<int>& arr, int start, int end)
{
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed elements
		for (int i = start + 1; i <= end - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed elements
		for (int i = start; i <= end - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}
}

// A utility function to print an array of size n
void printArray(std::vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
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
	///////nr threads = nr odd/evens - 186224 milliseconds

	std::vector<int> arr = generateRandomArray(1000, 1, 30);
	std::vector<int> arr2 = arr;
	std::vector<int> arr3 = arr;

	int size = arr.size();

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	oddEvenSortThreads(arr, size);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer
	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	printArray(arr, size);

	///////normal - 10.7223 milliseconds

	size = arr2.size();

	start = std::chrono::high_resolution_clock::now();  // Start the timer

	oddEvenSort(arr2, size);

	end = std::chrono::high_resolution_clock::now();  // Stop the timer
	duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	printArray(arr2, size);

	///////2 threads - 3.8347 milliseconds

	size = arr3.size();

	int numThreads = 2;
	int chunkSize = size / numThreads;

	start = std::chrono::high_resolution_clock::now();  // Start the timer
	std::vector<std::thread> threads;

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

		threads.emplace_back(oddEvenSortChunk, std::ref(arr3), threadStart, threadEnd);
	}

	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}

	end = std::chrono::high_resolution_clock::now();  // Stop the timer
	duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	printArray(arr3, size);

	return 0;
}