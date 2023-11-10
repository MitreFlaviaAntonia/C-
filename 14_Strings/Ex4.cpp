#include <iostream>
#include <string>
#include <vector>

std::string ToUpper(std::string str)
{
	int size = str.size();
	for(int i = 0; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - ('a' - 'A');
		}
	}
	return str;
}

std::string ToLower(std::string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + ('a' - 'A');
		}
	}
	return str;
}

int main()
{
	std::string str = "rOw1, roW2, Row3";
	str = ToUpper(str);
	std::cout << "String after toUpper: " << str << std::endl << std::endl;
	str = ToLower(str);
	std::cout << "String after toLower: " << str << std::endl << std::endl;
	
	return 0;
}