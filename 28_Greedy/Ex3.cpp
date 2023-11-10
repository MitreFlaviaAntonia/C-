/*#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& greedFactor, std::vector<int>& cookieSize)
{
	std::sort(greedFactor.begin(), greedFactor.end());
	std::sort(cookieSize.begin(), cookieSize.end());

	int grFctIndex = 0;
	int ckSzIndex = 0;
	int count = 0;

	while (grFctIndex < greedFactor.size() && grFctIndex < cookieSize.size())
	{
		if (cookieSize[grFctIndex] >= greedFactor[ckSzIndex])
		{
			count++;
			ckSzIndex++;
			grFctIndex++;
		}
		else
		{
			grFctIndex++;
		}
	}

	return count;
}

int main()
{
	std::vector<int> g1 = { 1, 2, 3 };
	std::vector<int> s1 = { 1, 1 };
	int result1 = findContentChildren(g1, s1);
	std::cout << "Maximum number of content children: " << result1 << std::endl;

	std::vector<int> g2 = { 1, 2 };
	std::vector<int> s2 = { 1, 2, 3 };
	int result2 = findContentChildren(g2, s2);
	std::cout << "Maximum number of content children: " << result2 << std::endl;
}*/