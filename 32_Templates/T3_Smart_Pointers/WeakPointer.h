#pragma once
#include <iostream>
#include "SharedPointer.h"

template<typename T>
class WeakPtr
{
private:
	T* m_weakPtr;
	SharedPtr<T>& m_shrPtr;

public:
	WeakPtr(SharedPtr<T>& sp) : m_shrPtr(sp), m_weakPtr(sp.get()) {}

	~WeakPtr()
	{
		std::cout << "WP destructor called\n";
	}

	T& operator*()
	{
		return *m_weakPtr;
	}
};