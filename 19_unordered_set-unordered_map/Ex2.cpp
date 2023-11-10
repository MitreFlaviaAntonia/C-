#include <iostream>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{
	if (s.length() != t.length())
	{
		return false;
	}

	std::unordered_map <char, int> map1;
	for (char c : s)
	{
		map1[c]++;
	}

	std::unordered_map <char, int> map2;
	for (char c : t)
	{
		map2[c]++;
	}

	if (map1.size() != map2.size())
	{
		return false;
	}

	for (const auto& pair : map1)
	{
		char key = pair.first;
		int count = pair.second;

		if (map2.find(key) == map2.end() || map2[key] != count)
		{
			return false;
		}
	}

	for (const auto& pair : map2)
	{
		char key = pair.first;
		int count = pair.second;

		if (map1.find(key) == map1.end() || map1[key] != count)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::cout << isAnagram("ana", "awn") << std::endl;

	return 0;
}