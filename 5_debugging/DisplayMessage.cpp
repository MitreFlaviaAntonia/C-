#include "DisplayMessage.h"

#include <iostream>

void DisplayMessage(const char* message)
{
	std::cout << message << std::endl;
}

void DisplayMessage(int number)
{
	std::cout << number << std::endl;
}

void DisplayMessage(float number)
{
	std::cout << number << std::endl;
}