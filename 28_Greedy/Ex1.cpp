/*#include <iostream>
#include <unordered_map>

class Solution
{
public:
	int longestPalindrome(std::string str)
	{
		std::unordered_map<char, int> counts;
		int length = 0;
		bool hasOddCount = false;

		for (int i = 0; i < str.length(); i++)
		{
			char chr = str[i];
			counts[chr]++;
		}

		for (auto it = counts.begin(); it != counts.end(); ++it)
		{
			int count = it->second;
			length += count / 2 * 2;

			if (count % 2 == 1)
			{
				hasOddCount = true;
			}
		}

		if (hasOddCount)
		{
			length++;
		}

		return length;
	}
};

int main()
{
	Solution solution;
	std::string input;

	std::cout << "Enter a string: ";
	std::cin >> input;

	int result = solution.longestPalindrome(input);
	std::cout << "Length of the longest palindrome: " << result << std::endl;

	return 0;
}*/