#include <iostream>
#include <string>

int main()
{
	std::string str;
	
	std::cout << "Read the string: ";
	std::cin >> str;
	
	std::string givenString = "Cat";
	std::cout << "Read the string: ";

	int position = str.find("Cat");
	if (position < str.size())
	{
		std::cout << str.substr(0, position);
	}
	else
	{
		std::cout << "Cat not found." << std::endl;
	}

	return 0;
}