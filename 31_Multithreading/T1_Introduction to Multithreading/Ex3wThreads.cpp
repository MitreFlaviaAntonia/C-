#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

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

// Merge sort function
void mergeSort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		std::thread thLeft([&]() {mergeSort(arr, left, mid); });
		std::thread thRight([&]() {mergeSort(arr, mid + 1, right); });

		thLeft.join();
		thRight.join();

		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

int main()
{
	std::vector<int> arr = { 5, 7, 1, 3, 2, 8, 6, 4 };
	int n = arr.size(); //8

	std::cout << "Original array: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	mergeSort(arr, 0, n - 1);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer

	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	std::cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
} // time = 6 milliseconds