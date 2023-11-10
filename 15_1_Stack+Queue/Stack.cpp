/*#include <iostream>

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
		m_size--;
	}
	
	int top()
	{
		return m_Arr[m_size - 1];
	}
};

int main()
{
	myStack stk(5);

	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.push(60);
	stk.push(70);
	stk.push(80);
	stk.push(90);

	std::cout << "Top element: " << stk.top() << std::endl;

	stk.pop();

	std::cout << "Top element after pop: " << stk.top() << std::endl;

	return 0;
}*/