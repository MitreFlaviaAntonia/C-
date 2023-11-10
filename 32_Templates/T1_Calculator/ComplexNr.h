#pragma once
#include <iostream>

template<typename T>
struct ComplexNr
{
	T real;
	T imaginary;
	ComplexNr() {};
	ComplexNr(T _real, T _imaginary) : real(_real), imaginary(_imaginary) {}
	void Print() const
	{
		std::cout << "(" << real << " : " << imaginary << ")\n";
	}
};