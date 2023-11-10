#include <iostream>

class Queue
{
private:
	int* m_arr;
	int m_front;
	int m_rear;
	int m_capacity;
	int m_count;

public:
	Queue(int size)
	{
		m_arr = new int[size];
		m_capacity = size;
		m_front = 0;
		m_rear = -1;
		m_count = 0;
	}

	~Queue()
	{
		delete[] m_arr;
	}

	void enqueue(int _value)
	{
		if (isFull())
		{
			std::cout << "Queue is full. Cannot enqueue." << std::endl;
			return;
		}
		m_rear = (m_rear + 1) % m_capacity;
		m_arr[m_rear] = _value;
		m_count++;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			std::cout << "Queue is empty. Cannot dequeue." << std::endl;
			return;
		}
		m_front = (m_front + 1) % m_capacity;
		m_count--;
	}

	int getFront()
	{
		if (isEmpty())
		{
			std::cout << "Queue is empty." << std::endl;
			return -1;
		}
		return m_arr[m_front];
	}

	int getRear()
	{
		if (isEmpty())
		{
			std::cout << "Queue is empty." << std::endl;
			return -1;
		}
		return m_arr[m_rear];
	}

	bool isEmpty()
	{
		return m_count == 0;
	}

	bool isFull()
	{
		return m_count == m_capacity;
	}

	int size()
	{
		return m_count;
	}
};

int main()
{
	Queue myQueue(7);

	myQueue.enqueue(23);
	myQueue.enqueue(545);
	myQueue.enqueue(232);
	myQueue.enqueue(10);
	myQueue.enqueue(102);

	std::cout << "Front element: " << myQueue.getFront() << std::endl;
	std::cout << "Rear element: " << myQueue.getRear() << std::endl;

	myQueue.dequeue();

	if (myQueue.isEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
	}
	else
	{
		std::cout << "Queue is not empty" << std::endl;
	}

	std::cout << "Size of the queue: " << myQueue.size() << std::endl;

	return 0;
}