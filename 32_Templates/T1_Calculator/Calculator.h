#pragma once
#include "ComplexNr.h"

//2 real
template<typename T, typename T1, typename T2>
class Calculator
{
public:
	T add(T1 a, T2 b);
	T subtract(T1 a, T2 b);
	T multiply(T1 a, T2 b);
	T divide(T1 a, T2 b);
};

template<typename T, typename T1, typename T2>
T Calculator<T, T1, T2>::add(T1 a, T2 b)
{
	return a + b;
}

template<typename T, typename T1, typename T2>
T Calculator<T, T1, T2>::subtract(T1 a, T2 b)
{
	return a - b;
}

template<typename T, typename T1, typename T2>
T Calculator<T, T1, T2>::multiply(T1 a, T2 b)
{
	return a * b;
}

template<typename T, typename T1, typename T2>
T Calculator<T, T1, T2>::divide(T1 a, T2 b)
{
	if (b == 0)
	{
		std::cout << "Cannot divide by zero." << std::endl;
		return -1;
	}
	return a / b;
}


//1 complex, 1 real
template<typename T, typename T1, typename T2>
class Calculator<ComplexNr<T>, ComplexNr<T1>, T2>
{
public:
	ComplexNr<T> add(ComplexNr<T1> a, T2 b);
	ComplexNr<T> subtract(ComplexNr<T1> a, T2 b);
	ComplexNr<T> multiply(ComplexNr<T1> a, T2 b);
	ComplexNr<T> divide(ComplexNr<T1> a, T2 b);
};

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, T2>::add(ComplexNr<T1> n1, T2 n2)
{
	ComplexNr<T> result;
	result.real = n1.real + n2;
	result.imaginary = n1.imaginary;
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, T2>::subtract(ComplexNr<T1> n1, T2 n2)
{
	ComplexNr<T> result;
	result.real = n1.real - n2;
	result.imaginary = n1.imaginary;
	return result;
} 
template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, T2>::multiply(ComplexNr<T1> n1, T2 n2)
{
	ComplexNr<T> result;
	result.real = n1.real * n2;
	result.imaginary = n1.imaginary * n2;
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, T2>::divide(ComplexNr<T1> n1, T2 n2)
{
	ComplexNr<double> result;
	if (n2 == 0)
	{
		std::cout << "Cannot divide by zero." << std::endl;
		return result;
	}
	
	result.real = n1.real / n2;
	result.imaginary = n1.imaginary / n2;
	return result;
}

//1 real, 1 complex
template<typename T, typename T1, typename T2>
class Calculator<ComplexNr<T>, T1, ComplexNr<T2>>
{
public:
	ComplexNr<T> add(T1 a, ComplexNr<T2> b);
	ComplexNr<T> subtract(T1 a, ComplexNr<T2> b);
	ComplexNr<T> multiply(T1 a, ComplexNr<T2> b);
	ComplexNr<T> divide(T1 a, ComplexNr<T2> b);
};

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, T1, ComplexNr<T2>>::add(T1 n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	result.real = n1 + n2.real;
	result.imaginary = n2.imaginary;
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, T1, ComplexNr<T2>>::subtract(T1 n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	result.real = n1 - n2.real;
	result.imaginary = -1 * n2.imaginary;
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, T1, ComplexNr<T2>>::multiply(T1 n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	result.real = n2.real * n1;
	result.imaginary = n2.imaginary * n1;
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, T1, ComplexNr<T2>>::divide(T1 n1, ComplexNr<T2> n2)//todo
{
	ComplexNr<T> result;
	result.real = n1 - n2.real;
	result.imaginary = -1 * n2.imaginary;
	return result;
}

//2 complex
template<typename T, typename T1, typename T2>
class Calculator<ComplexNr<T>, ComplexNr<T1>, ComplexNr<T2>>
{
public:
	ComplexNr<T> add(ComplexNr<T1> a, ComplexNr<T2> b);
	ComplexNr<T> subtract(ComplexNr<T1> a, ComplexNr<T2> b);
	ComplexNr<T> multiply(ComplexNr<T1> a, ComplexNr<T2> b);
	ComplexNr<T> divide(ComplexNr<T1> a, ComplexNr<T2> b);
};

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, ComplexNr<T2>>::add(ComplexNr<T1> n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	result.real = static_cast<double>(n1.real + n2.real);
	result.imaginary = static_cast<double>(n1.imaginary + n2.imaginary);
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, ComplexNr<T2>>::subtract(ComplexNr<T1> n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	result.real = static_cast<double>(n1.real - n2.real);
	result.imaginary = static_cast<double>(n1.imaginary - n2.imaginary);
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, ComplexNr<T2>>::multiply(ComplexNr<T1> n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	if (n1.imaginary * n2.imaginary >= 0)
	{
		if (n1.real * n2.imaginary + n2.real * n1.imaginary != 0)
		{
			result.real = n1.real * n2.real - n1.imaginary * n2.imaginary;
			result.imaginary = n1.real * n2.imaginary + n2.real * n1.imaginary;
		}
		else
		{
			result.real = n1.real * n2.real - n1.imaginary * n2.imaginary;
			result.imaginary = 0;
		}
	}
	else
	{
		if (n1.real * n2.imaginary - n2.real * n1.imaginary != 0)
		{
			result.real = n1.real * n2.real + n1.imaginary * n2.imaginary;
			result.imaginary = n1.real * n2.imaginary - n2.real * n1.imaginary;
		}
		else
		{
			result.real = n1.real * n2.real + n1.imaginary * n2.imaginary;
			result.imaginary = 0;
		}
	}
	return result;
}

template<typename T, typename T1, typename T2>
ComplexNr<T> Calculator<ComplexNr<T>, ComplexNr<T1>, ComplexNr<T2>>::divide(ComplexNr<T1> n1, ComplexNr<T2> n2)
{
	ComplexNr<T> result;
	if (n2.real == 0 && n2.imaginary == 0)
	{
		std::cout << "Cannot divide by zero." << std::endl;
		return result;
	}
	result.real = static_cast<double>(n1.real * n2.real + n1.imaginary * n2.imaginary) / static_cast<double>(n2.real * n2.real + n2.imaginary * n2.imaginary);
	result.imaginary = static_cast<double>(n1.imaginary * n2.real - n1.real * n2.imaginary) / static_cast<double>(n2.real * n2.real + n2.imaginary * n2.imaginary);
	
	return result;
}