#include <iostream>
#include <thread>
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
	int n = 10;

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	std::thread t1(countToN, n);  // Create a thread and pass the function and argument
	std::thread t2(countToN, n);  // Create a thread and pass the function and argument

	t1.join();  // Wait for the thread to finish
	t2.join();  // Wait for the thread to finish

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer
	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
	
	return 0;
} // time = 7 milliseconds