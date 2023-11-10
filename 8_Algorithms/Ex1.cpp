#include <iostream>

int main()
{
    unsigned long long int number;
    std::cout << "The number is: ";
    std::cin >> number;
    int primeDigitsCount = 0;

	while (number != 0)
	{
		if (number % 10 == 2 || number % 10 == 3 || number % 10 == 5 || number % 10 == 7 || number % 10 == 9)
		{
			primeDigitsCount++;
		}
		number = number / 10;
	}

    std::cout << "The number has " << primeDigitsCount << " prime digits";
}