#include <iostream>

class myStack
{
private:
	int* m_Arr;
	int m_size;
	int m_capacity;

public:
	myStack(int capacity)
	{
		m_Arr = new int[capacity];
		m_size = 0;
		m_capacity = capacity;
	}

	void Grow()
	{
		m_capacity *= 2;
		int* newArr = new int[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			newArr[i] = m_Arr[i];
		}
		delete[] m_Arr;
		m_Arr = newArr;
	}

	void push(int value)
	{
		if (m_size == m_capacity)
		{
			Grow();
		}
		m_Arr[m_size] = value;
		m_size++;
	}
	
	void pop()
	{
		if (m_size > 0)
		{
			m_size--;
		}
		else
		{
			std::cout << "Stack is empty. Cannot perform pop operation." << std::endl;
		}
	}

	int top()
	{
		if (m_size > 0)
		{
			return m_Arr[m_size - 1];
		}
		
		std::cout << "Stack is empty. Cannot retrieve top element." << std::endl;
		return -1; // Return a default value indicating an empty stack
	}
};
