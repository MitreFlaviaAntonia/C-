#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::vector<int>> memo;

std::vector<int> beautifulArray(int n)
{
	if (memo.count(n))
	{
		return memo[n];
	}

	std::vector<int> result;
	if (n == 1)
	{
		result.push_back(1);
	}
	else
	{
		std::vector<int> odd = beautifulArray((n + 1) / 2);
		std::vector<int> even = beautifulArray(n / 2);

		for (int i = 0; i < odd.size(); i++)
		{
			int num = odd[i];
			result.push_back(num * 2 - 1);
		}

		for (int i = 0; i < even.size(); i++)
		{
			int num = even[i];
			result.push_back(num * 2);
		}
	}

	memo[n] = result;
	return result;
}

int main()
{
	int n = 4;
	std::vector<int> result = beautifulArray(n);

	std::cout << "Beautiful array of length " << n << ": ";
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	n = 5;
	result = beautifulArray(n);

	std::cout << "Beautiful array of length " << n << ": ";
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}