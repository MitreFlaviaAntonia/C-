#include <iostream>
#include <vector>
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

		// Sort first half
		mergeSort(arr, left, mid);

		// Sort second half
		mergeSort(arr, mid + 1, right);

		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

int main()
{
	std::vector<int> arr(100);

	int n = arr.size();

	// generating random values in array
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
		std::cout << arr[i] << " ";
	}

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	mergeSort(arr, 0, n - 1);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer

	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration
	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	std::cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
} // time = 0 milliseconds for size 8 arr
 // time = 0.15 milliseconds for arr size 100