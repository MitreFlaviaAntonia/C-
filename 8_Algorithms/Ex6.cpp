#include <iostream>

int greatestCommonDivisor(int num1, int num2)
{
	while (num2 != 0)
	{
		int temp = num2;
		num2 = num1 % num2;
		num1 = temp;
	}
	return num1;
}

int main()
{
	int length;
	std::cout << "Enter the number of elements: ";
	std::cin >> length;

	int gcdResult = 1;
	std::cout << "Enter the elements: ";
	for (int i = 0; i < length; i++)
	{
		int number;
		std::cin >> number;
		if (i == 0)
		{
			gcdResult = number;
		}
		else
		{
			gcdResult = greatestCommonDivisor(gcdResult, number);
		}
	}

	std::cout << "The greatest common divisor of the numbers is: " << gcdResult << std::endl;

	return 0;
}