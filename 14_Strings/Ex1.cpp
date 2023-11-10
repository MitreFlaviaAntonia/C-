#include <iostream>
#include <string>

std::string ReplaceAll(const std::string& str, const std::string& toReplace, const std::string& replaceWith)
{
	std::string result = str;
	size_t pos = result.find(toReplace);

	while (pos != std::string::npos)
	{
		result.replace(pos, toReplace.length(), replaceWith);
		pos = result.find(toReplace, pos + replaceWith.length());
	}

	return result;
}

int main()
{
	std::string str = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness.";
	std::string toReplace = "was";
	std::string replaceWith = "is";

	std::string replacedStr = ReplaceAll(str, toReplace, replaceWith);

	std::cout << "Original string: " << str << std::endl;
	std::cout << "String after replacing: " << replacedStr << std::endl;

	return 0;
}