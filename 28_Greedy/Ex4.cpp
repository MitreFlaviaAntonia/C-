#include <iostream>
#include <vector>
#include <algorithm>

int maxCoins(std::vector<int>& piles)
{
	int myCoins = 0;
	sort(piles.begin(), piles.end(),std::greater<int>());
	int limit = piles.size() / 3;
	for (int i = 1; i < piles.size(); i += 2)
	{
		if (limit == 0)
		{
			break;
		}
		myCoins += piles[i];
		limit--;
	}
	return myCoins;
}

int main()
{
	std::vector<int> piles = { 2, 4, 1, 2, 7, 8 };
	int maxCoinsCount = maxCoins(piles);
	std::cout << "Maximum number of coins: " << maxCoinsCount << std::endl;
	return 0;
}