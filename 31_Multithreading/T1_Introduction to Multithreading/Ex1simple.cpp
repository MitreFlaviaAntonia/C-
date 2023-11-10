#include <iostream>
#include <chrono>

void countToN(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int n = 100;

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	countToN(n);  // Call the function directly

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer

	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	return 0;
} // time = 4 milliseconds