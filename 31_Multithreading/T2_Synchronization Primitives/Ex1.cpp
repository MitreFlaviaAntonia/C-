#include <iostream>
#include <vector>
#include <thread>
#include <barrier>
#include <random>

std::barrier my_barrier{ 11 };
int threadCnt = 0;
// Merge two sorted sub arrays into one sorted array
void merge(std::vector<int>& arr, int left, int mid, int right)
{
	int leftArrLen = mid - left + 1;
	int rightArrLen = right - mid;
	// Create temporary arrays
	std::vector<int> leftArr(leftArrLen);
	std::vector<int> rightArr(rightArrLen);
	// Copy data to temporary arrays
	for (int i = 0; i < leftArrLen; i++)
	{
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < rightArrLen; j++)
	{
		rightArr[j] = arr[mid + 1 + j];
	}
	// Merge the temporary arrays back into arr
	int i = 0; // Initial index of first sub array
	int j = 0; // Initial index of second sub array
	int k = left; // Initial index of merged sub array
	while (i < leftArrLen && j < rightArrLen)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of left, if any
	while (i < leftArrLen)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	// Copy the remaining elements of right, if any
	while (j < rightArrLen)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
	//std::cout << " L= " << left << " " << std::endl;
	//std::cout << " R= " << right << " " << std::endl;
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		// Sort first half
		mergeSort(arr, left, mid);
		// Sort second half
		mergeSort(arr, mid + 1, right);
		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

void mergeSortBarrier(std::vector<int>& arr, int left, int right, int threadID)
{
	std::cout << "apelx " << std::endl;
	threadCnt++;
	//std::cout << "thread cnt = " << threadCnt;
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
		if (threadCnt % 4 == 0)
		{
			std::cout << "thread cnt = " << threadCnt << std::endl;
			std::cout << " m1 ";
			my_barrier.arrive_and_drop();
		}
		else
		{
			//std::cout << threadCnt;
			std::cout << " m2 ";
			my_barrier.arrive_and_wait();
		}
	}
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
	std::vector<int> arr = generateRandomArray(44, 1, 100000);
	int arrSize = arr.size();
	int numThreads = 11;  // Change this to the number of threads you want to use
	std::vector<std::thread> threads(11);
	int chunkSize = arrSize / numThreads;
	

	for (int i = 0; i < numThreads; i++)
	{
		int threadStart = i * chunkSize;
		int threadEnd;
		if (i == numThreads - 1)
		{
			threadEnd = arrSize - 1;
		}
		else
		{
			threadEnd = (i + 1) * chunkSize;
		}
		threads[i] = std::thread(mergeSortBarrier, std::ref(arr), threadStart, threadEnd, i);
	}

	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}

	std::cout << "Sorted array: ";
	for (int num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
	return 0;
}