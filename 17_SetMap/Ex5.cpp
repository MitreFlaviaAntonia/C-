#include <iostream>
#include <vector>
#include <set>

int main()
{
	int nrNumbers = 6;
	std::vector<int> nrVector = { 1, 2, 6, 5, 4, 3 };
	int greaterThan = 3;
	std::set<int> nrSet;

	for (int i = 0; i < nrVector.size(); ++i)
	{
		nrSet.insert(nrVector[i]);
		std::set<int>::iterator it = nrSet.upper_bound(greaterThan);
		if (it != nrSet.end())
		{
			std::cout << *it << std::endl;
		}
		else
		{
			std::cout << "-1" << std::endl;
		}
	}

	return 0;
}