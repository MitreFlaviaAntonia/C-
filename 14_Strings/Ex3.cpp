#include <iostream>
#include <string>
#include <vector>

std::string Join(std::vector<std::string> strings, std::string delimitator)
{
	std::string result = "\0";
	int size = strings.size();
	for(int i = 0; i < size; i++)
	{
		if(i < size - 1)
			result = result + strings[i] + delimitator;
		else
			result = result + strings[i];
	}

	return result;
}

int main()
{
	std::vector<std::string> stringsToJoin = { "a", "b", "c" };
	std::string delimitator = ", ";
	std::string str = Join(stringsToJoin, delimitator);
	std::cout << "String after joining: " << str << std::endl << std::endl;
	return 0;
}