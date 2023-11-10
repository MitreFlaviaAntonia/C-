#include <iostream>

bool isFibonacci(int num)
{
	int f1 = 0;
	int f2 = 1;

	while (f2 < num)
	{
		int temp = f2;
		f2 = f1 + f2;
		f1 = temp;
	}

	if (f2 == num)
	{
		return true;
	}

	return false;
}

int main()
{
	int length;
	std::cout << "How many numbers do you want to read? ";
	std::cin >> length;
	int number;
	
	for (int i = 0; i < length; i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> number;
	
		if (isFibonacci(number))
		{
			std::cout << number << " is from the Fibonacci sequence." << std::endl;
		}
		else
		{
			std::cout << number << " is not from the Fibonacci sequence." << std::endl;
		}
	}
	return 0;
}