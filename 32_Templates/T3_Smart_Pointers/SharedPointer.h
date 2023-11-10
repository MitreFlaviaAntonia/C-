#pragma once
#include <iostream>

template<typename T>
class SharedPtr
{
private:
	T* m_shrPtr;
	int* m_refCnt;

public:

	SharedPtr(T* pointer) : m_shrPtr(pointer), m_refCnt(new int(1)){}

	SharedPtr(const SharedPtr<T>& other) : m_shrPtr(other.m_shrPtr), m_refCnt(other.m_refCnt)
	{
		(*m_refCnt)++;
	}

	~SharedPtr()
	{
		(*m_refCnt)--;
		if (*m_refCnt == 0)
		{
			delete m_shrPtr;
			delete m_refCnt;
			std::cout << "SP deleted\n";
		}
	}

	T* get()
	{
		return m_shrPtr;
	}

	void AddRef()
	{
		(*m_refCnt)++;
	}

	void RemoveRef()
	{
		(*m_refCnt)--;
	}

	T& operator* ()
	{
		return *m_shrPtr;
	}
};