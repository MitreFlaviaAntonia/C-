#include <iostream>

class BinaryHeap
{
private:
	int* m_heapArray;
	int m_capacity;
	int m_heapSize;

public:
	BinaryHeap(int capacity)
	{
		m_capacity = capacity;
		m_heapArray = new int[capacity];
		m_heapSize = 0;
	}

	int getMin()
	{
		if (m_heapSize == 0)
		{
			std::cout << "Heap is empty!" << std::endl;
			return -1;
		}
		return m_heapArray[0];
	}

	void extractMin()
	{
		if (m_heapSize <= 0)
		{
			std::cout << "Heap is empty!" << std::endl;
			return;
		}

		m_heapSize--;

		if (m_heapSize == 1)
		{
			return;
		}
		
		int root = m_heapArray[0];
		m_heapArray[0] = m_heapArray[m_heapSize - 1];
		m_heapSize--;
		heapify(0);

		std::cout << "Extracted min: " << root << std::endl;
	}

	void decreaseKey(int _index, int _newValue)
	{
		if (_index >= m_heapSize)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}

		if (m_heapArray[_index] < _newValue)
		{
			std::cout << "New value is greater than current value!" << std::endl;
			return;
		}

		m_heapArray[_index] = _newValue;
		while (_index > 0 && m_heapArray[parent(_index)] > m_heapArray[_index])
		{
			std::swap(m_heapArray[_index], m_heapArray[parent(_index)]);
			_index = parent(_index);
		}

		std::cout << "Key decreased successfully!" << std::endl;
	}

	void insert(int _value)
	{
		if (m_heapSize == m_capacity)
		{
			std::cout << "Heap is full!" << std::endl;
			return;
		}

		m_heapSize++;
		int index = m_heapSize - 1;
		m_heapArray[index] = _value;

		while (index > 0 && m_heapArray[parent(index)] > m_heapArray[index])
		{
			std::swap(m_heapArray[index], m_heapArray[parent(index)]);
			index = parent(index);
		}

		std::cout << "Value inserted successfully!" << std::endl;
	}

	void deleteKey(int _index)
	{
		if (_index >= m_heapSize)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}

		decreaseKey(_index, INT_MIN);
		extractMin();

		std::cout << "Key deleted successfully!" << std::endl;
	}

private:
	int parent(int _index)
	{
		return (_index - 1) / 2;
	}

	int leftChild(int _index)
	{
		return (2 * _index) + 1;
	}

	int rightChild(int _index)
	{
		return (2 * _index) + 2;
	}

	void heapify(int _index)
	{
		int smallest = _index;
		int left = leftChild(_index);
		int right = rightChild(_index);

		if (left < m_heapSize && m_heapArray[left] < m_heapArray[smallest])
		{
			smallest = left;
		}

		if (right < m_heapSize && m_heapArray[right] < m_heapArray[smallest])
		{
			smallest = right;
		}

		if (smallest != _index)
		{
			std::swap(m_heapArray[_index], m_heapArray[smallest]);
			heapify(smallest);
		}
	}
};

int main()
{
	BinaryHeap heap(10);

	heap.insert(5);
	heap.insert(3);
	heap.insert(8);
	heap.insert(1);
	heap.insert(10);

	heap.deleteKey(0);

	std::cout << "Min element: " << heap.getMin() << std::endl;

	heap.extractMin();
	std::cout << "Min element: " << heap.getMin() << std::endl;

	std::cout << "Min element: " << heap.getMin() << std::endl;

	heap.decreaseKey(2, 2);
	std::cout << "Min element: " << heap.getMin() << std::endl;

	return 0;
}