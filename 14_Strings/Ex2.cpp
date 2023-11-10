#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, const std::string& separator)
{
	std::vector<std::string> result;
	size_t startPos = 0;
	size_t endPos = str.find(separator);

	while (endPos != std::string::npos)
	{
		std::string token = str.substr(startPos, endPos - startPos);
		result.push_back(token);
		startPos = endPos + separator.length();
		endPos = str.find(separator, startPos);
	}

	std::string lastToken = str.substr(startPos);
	result.push_back(lastToken);

	return result;
}


int main()
{
	std::string str = "row1, row2, row3";
	std::cout << "Original string: " << str << std::endl;

	std::vector<std::string> splittedStrings(50, "\0");
	splittedStrings = Split(str, ", ");

	for (int i = 0; i < splittedStrings.size(); ++i)
	{
		std::cout << "String after splitting: " << splittedStrings[i] << std::endl << std::endl;
	}

	return 0;
}