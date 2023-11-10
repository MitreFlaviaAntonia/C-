#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	T* arrayPtr;
	int capacity;
	int size;

public:
	Array(int _capacity);
	void addElement(T element);
	void Grow();
	void removeElement(int pos);
	int getCapacity();
	int getSize();
	T& operator[](int index) const;
};

template <typename T>
Array<T>::Array(int _capacity)
{
	capacity = _capacity;
	arrayPtr = new T[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		arrayPtr[i] = 0;
	}
	size = 0;
}

template <typename T>
void Array<T>::Grow()
{
	capacity *= 2;
	T* newArr = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arrayPtr[i];
	}
	delete[] arrayPtr;
	arrayPtr = newArr;
}

template <typename T>
void Array<T>::addElement(T element)
{
	if (size == capacity)
	{
		Grow();
	}
	arrayPtr[size] = element;
	size++;
}

template <typename T>
void Array<T>::removeElement(int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	T* newArr = new T[capacity];

	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			newArr[j] = arrayPtr[i];
			j++;
		}
	}

	delete[] arrayPtr;
	arrayPtr = newArr;
	size--;

	std::cout << "Element at index " << index << " removed successfully!" << std::endl;
}

template <typename T>
int Array<T>::getCapacity()
{
	return capacity;
}

template <typename T>
int Array<T>::getSize()
{
	return size;
}

template <typename T>
T& Array<T>::operator[](int pos) const
{
	return arrayPtr[pos];
}