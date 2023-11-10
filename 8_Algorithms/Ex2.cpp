#include <iostream>

int main()
{
	int number;
	std::cout << "Enter an integer number: ";
	std::cin >> number;
	int pow = 1;
	while (number != 0)
	{
		if ((number & 1) == 1)
		{
			std::cout << pow  << " ";
		}
		number = number >> 1;
		pow *= 2;
	}

	return 0;
}

/*#include <iostream>

int main()
{
	int number;
	std::cout << "Enter an integer number: ";
	std::cin >> number;
	
	int saveNumber = number;
	
	while(saveNumber != 0)
	{
		int pow = 1;
		while (number / 2 != 0)
		{
			pow = pow * 2;
			number = number / 2;
		}
		std::cout << pow << " ";
		number = saveNumber - pow;
		saveNumber = number;
	}
	
	return 0;
}*/