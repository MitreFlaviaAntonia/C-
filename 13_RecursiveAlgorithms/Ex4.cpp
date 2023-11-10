#include <iostream>

int reverse(int number, int temp)
{
	if (number == 0)
		return temp;

	temp = (temp * 10) + (number % 10);

	return reverse(number / 10, temp);
}

int main()
{

	int number = 15751;

	if (reverse(number, 0) == number)
		std::cout << "The number is palindrome" << std::endl;
	else
		std::cout << "The number is not palindrome" << std::endl;
	return 0;
}