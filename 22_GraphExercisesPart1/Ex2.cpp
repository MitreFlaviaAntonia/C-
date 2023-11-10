/*#include <iostream>
#include <vector>


int findJudge(int n, std::vector<std::vector<int>>& trust)
{
	int nrEdgesMax = n - 1;
	std::vector<int> trustCnt(n + 1, 0);
	std::vector<int> trustsNobodyCnt(n + 1, 0);

	for (int i = 0; i < trust.size(); i++)
	{
		trustCnt[trust[i][1]]++;
		trustsNobodyCnt[trust[i][0]]++;
	}

	for (int currentNode = 1; currentNode <= n; currentNode++)
	{
		if (trustCnt[currentNode] == nrEdgesMax && trustsNobodyCnt[currentNode] == 0)
		{
			return currentNode;
		}
	}

	return -1;
}


int main()
{
	std::vector<std::vector<int>> trust = { {2, 1}, {3, 1}, {4, 1} };
	int nrNodes = 4;
	std::cout << "The town judge is node: " << findJudge(nrNodes, trust);

	return 0;
}*/