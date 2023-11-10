#include <iostream>

class myQueue
{

private:
	int* m_Arr;
	int* m_Begin;
	int* m_End;
	int m_size;
	int m_capacity;

public:
	myQueue(int capacity)
	{
		m_Arr = new int[capacity];
		m_Begin = (m_Arr+1);
		m_End = m_Arr;
		m_size = 0;
		m_capacity = capacity;
	}

	int getEnd()
	{
		return *m_End;
	}

	int getCapacity()
	{
		return m_capacity;
	}

	void Grow()
	{
		int newCapacity = m_capacity * 2;
		int* newArr = new int[newCapacity];
		int i = 0;
		for (int* ptr = m_Begin; ptr != m_End+1;)
		{
			newArr[i] = *ptr;
			ptr++;
			i++;
			if (ptr == m_Arr + 1 + m_capacity)
			{
				ptr = m_Arr;
			}
		}
		m_capacity = newCapacity;
		m_Begin = newArr;
		m_End = newArr + m_size - 1;
		//delete[] m_Arr;
		m_Arr = newArr;
		
	}

	void push_back(int value)
	{
		if (m_size == m_capacity)
		{
			Grow();
		}
		if (m_End == m_Arr + m_capacity)
		{
			m_End = m_Arr;
		}
		else
		{
			m_End++;
		}
		*m_End = value;
		m_size++;
	}

	void pop_front()
	{
		if (m_Begin == m_Arr + m_capacity)
		{
			m_Begin = m_Arr;
		}
		m_Begin++;
		m_size--;
	}

	int front()
	{
		return *m_Begin;
	}
};

int main()
{
	myQueue que(5);

	que.push_back(10);
	que.push_back(20);
	que.push_back(30);
	que.push_back(40);
	que.push_back(50);

	que.pop_front();

	que.push_back(60);
	que.push_back(70);

	std::cout << "Front element: " << que.front() << std::endl;
	std::cout << "End: " << que.getEnd() << std::endl;
	std::cout << "Capacity: " << que.getCapacity() << std::endl;

	que.pop_front();
	
	std::cout << "Front element after popping: " << que.front() << std::endl;

	return 0;
}