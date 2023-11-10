#include <iostream>
#include <stdexcept>

class Vector
{
private:
	int* m_arr;
	int m_size;
	int m_capacity;

public:
	Vector()
		: m_arr(nullptr)
		, m_size(0)
		, m_capacity(0)
	{}

	void reserveCapacity()
	{
		if (m_size == m_capacity)
		{
			if (m_capacity == 0)
			{
				Reserve(1);
			}
			else
			{
				Reserve(m_capacity * 2);
			}
		}
	}

	bool Empty() const
	{
		return m_size == 0;
	}

	int Size() const
	{
		return m_size;
	}

	int Capacity() const
	{
		return m_capacity;
	}

	void PushBack(int element)
	{
		reserveCapacity();
		m_arr[m_size] = element;
		m_size++;
	}

	void PopBack()
	{
		if (m_size > 0)
		{
			m_size--;
		}
		else
		{
			throw std::out_of_range("Vector is empty");
		}
	}

	int At(int _index) const
	{
		if (_index >= 0 && _index < m_size)
		{
			return m_arr[_index];
		}
		else
		{
			throw std::out_of_range("Index out of range");
		}
	}

	int& operator[](int _index)
	{
		return m_arr[_index];
	}

	void Resize(int _newSize)
	{
		if (_newSize < 0)
		{
			throw std::invalid_argument("Invalid size");
		}
		if (_newSize > m_size)
		{
			Reserve(_newSize);
		}
		m_size = _newSize;
	}

	void Reserve(int _newCapacity)
	{
		if (_newCapacity > m_capacity)
		{
			int* newArr = new int[_newCapacity];
			for (int i = 0; i < m_size; i++)
			{
				newArr[i] = m_arr[i];
			}
			delete[] m_arr;
			m_arr = newArr;
			m_capacity = _newCapacity;
		}
	}

	void Clear()
	{
		m_size = 0;
	}

	void Insert(int _index, int _element)
	{
		if (_index < 0 || _index > m_size)
		{
			throw std::out_of_range("Index out of range");
		}
		reserveCapacity();
		for (int i = m_size; i > _index; i--)
		{
			m_arr[i] = m_arr[i - 1];
		}
		m_arr[_index] = _element;
		m_size++;
	}

	void Erase(int _index)
	{
		if (_index < 0 || _index >= m_size)
		{
			throw std::out_of_range("Index out of range");
		}
		for (int i = _index; i < m_size - 1; i++)
		{
			m_arr[i] = m_arr[i + 1];
		}
		m_size--;
	}
};

int main()
{
	Vector vec;
	std::cout << "Empty: " << vec.Empty() << std::endl;
	std::cout << "Size: " << vec.Size() << std::endl;
	std::cout << "Capacity: " << vec.Capacity() << std::endl;

	vec.PushBack(35);
	vec.PushBack(45);
	vec.PushBack(15);
	vec.PushBack(120);

	std::cout << "Empty: " << vec.Empty() << std::endl;
	std::cout << "Size: " << vec.Size() << std::endl;
	std::cout << "Capacity: " << vec.Capacity() << std::endl;

	std::cout << "Element at index 1: " << vec.At(1) << std::endl;
	std::cout << "Element at index 2: " << vec[3] << std::endl;

	vec.Resize(7);
	std::cout << "Size after resize: " << vec.Size() << std::endl;

	vec.Clear();
	std::cout << "Size after clear: " << vec.Size() << std::endl;

	return 0;
}