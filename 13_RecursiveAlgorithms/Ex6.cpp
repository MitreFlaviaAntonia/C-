#include <iostream>
#include <vector>

bool isPrime(int num, int divisor = 2)
{

	if (num <= 2)
	{
		return (num == 2);
	}
	if (num % divisor == 0)
	{
		return false;
	}
	if (divisor * divisor > num)
	{
		return true;
	}

	return isPrime(num, divisor + 1);
}

int fibonacciNumbers(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}
	
	return fibonacciNumbers(n - 2) + fibonacciNumbers(n - 1);
}

int main()
{
	int n;
	std::cout << "Enter the value of n: ";
	std::cin >> n;

	std::cout << "The first " << n << " prime numbers of the Fibonacci sequence are: ";

	int fiboPrimeCnt = 0;
	int i = 0;
	while(fiboPrimeCnt < n)
	{
		int fiboResult = fibonacciNumbers(i);
		if(isPrime(fiboResult))
		{
			std::cout << fiboResult << " ";
			fiboPrimeCnt++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}