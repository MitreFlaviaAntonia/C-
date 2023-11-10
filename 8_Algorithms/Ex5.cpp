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

bool areCoprime(int num1, int num2)
{
	return greatestCommonDivisor(num1, num2) == 1;
}

bool fibElemForIndex(int index)
{
	int f1 = 1;
	int f2 = 1;
	int countIndex = 3;
	int temp;

	while (countIndex < index)
	{
		temp = f2;
		f2 = f1 + f2;
		f1 = temp;
		countIndex++;
	}

	return f2;
}

int main()
{
	int length;
	std::cout << "How many pairs of indices do you want to read? ";
	std::cin >> length;
	int firstIndex;
	int secondIndex;
	int firstFibElem;
	int secondFibElem;

	for (int i = 0; i < length; i++)
	{
		std::cout << "Enter the first index: ";
		std::cin >> firstIndex;
		std::cout << "Enter the second index: ";
		std::cin >> secondIndex;

		firstFibElem = fibElemForIndex(firstIndex);
		secondFibElem = fibElemForIndex(secondIndex);

		if (areCoprime(firstFibElem, secondFibElem))
		{
			std::cout << "The numbers are co-prime" << std::endl;
		}
		else
		{
			std::cout << "The numbers are not co-prime" << std::endl;
		}
	}
	return 0;
}