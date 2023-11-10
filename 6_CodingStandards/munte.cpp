#include <iostream>

bool isMountain(long long number_)
{
	int digit = 0;
	int lastDigit;
	bool isStrictlyIncreasing = true;
	bool isStrictlyDecreasing = true;

	while (number_ != 0)
	{
		lastDigit = digit;
		digit = number_ % 10;
		if (lastDigit >= digit)
		{
			isStrictlyIncreasing = false;
		}

		if (!isStrictlyIncreasing && lastDigit <= digit)
		{
			if (lastDigit <= digit)
			{
				isStrictlyDecreasing = false;
			}
		}
		number_ /= 10;
	}

	return isStrictlyDecreasing;
}

int main()
{
	long long number;
	std::cout << "Read the value for number: ";
	std::cin >> number;

	if (isMountain(number))
	{
		std::cout << "The number is a mountain";
	}
	else
	{
		std::cout << "The number is not mountain";
	}
	return 0;
}