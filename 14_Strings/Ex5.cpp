#include <iostream>
#include <string>
#include <vector>

int countAlliterations(const std::vector<std::string>& strings)
{
	std::vector<std::string> result;
	bool hasAlliteration = false;
	int cnt = 0;
	for (int i = 1; i < strings.size(); ++i)
	{
		if (std::tolower(strings[i - 1][0]) == std::tolower(strings[i][0]))
		{
			if(!hasAlliteration)
			{
				cnt++;
			}
			hasAlliteration = true;
		}
		else
		{
			hasAlliteration = false;
		}
	}

	return cnt;
}

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
	std::string str = "Peter Piper picked a peck of picked peppers";
	std::cout << "Original string: " << str << std::endl;

	std::vector<std::string> strings(50, "\0");
	strings = Split(str, " ");
	int cnt = countAlliterations(strings);

	std::cout << "There are " << cnt << " alliterations." << std::endl;
	
	return 0;
}