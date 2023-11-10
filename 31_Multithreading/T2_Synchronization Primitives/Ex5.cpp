#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore
{
public:
	Semaphore(int count = 0) : count_(count) {}

	void acquire()
	{
		std::unique_lock<std::mutex> lock(mutex_);
		while (count_ == 0)
		{
			condition_.wait(lock);
		}
		count_--;
	}

	void release()
	{
		std::lock_guard<std::mutex> lock(mutex_);
		count_++;
		condition_.notify_one();
	}

private:
	int count_;
	std::mutex mutex_;
	std::condition_variable condition_;
};

int main()
{
	Semaphore semaphore(2); // Initialize with 2 permits

	std::thread t1([&]()
		{
			semaphore.acquire();
			std::cout << "Thread 1 acquired the semaphore." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			semaphore.release();
			std::cout << "Thread 1 released the semaphore." << std::endl;
		});

	std::thread t2([&]()
		{
			semaphore.acquire();
			std::cout << "Thread 2 acquired the semaphore." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			semaphore.release();
			std::cout << "Thread 2 released the semaphore." << std::endl;
		});

	t1.join();
	t2.join();

	return 0;
}