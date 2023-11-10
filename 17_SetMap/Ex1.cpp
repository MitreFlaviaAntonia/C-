#include <iostream>
#include <set>

std::set<int> mergeTwoSetsStl(std::set<int> set1, std::set<int> set2)
{
	if (set1.empty())
		return set2;

	if (set2.empty())
		return set1;

	std::set<int> resultSet;
	resultSet.insert(set1.begin(), set1.end());
	resultSet.insert(set2.begin(), set2.end());
	return resultSet;
}

std::set<int> mergeTwoSetsIter(std::set<int> set1, std::set<int> set2)
{
	if (set1.empty())
		return set2;

	if (set2.empty())
		return set1;

	auto it1 = set1.begin();
	auto it2 = set2.begin();

	std::set<int> resultSet;

	while(it1 != set1.end() && it2 != set2.end())
	{
		if (*it1 < *it2)
		{
			resultSet.insert(*it1);
			++it1;
		}
		else
			if (*it1 > *it2)
			{
				resultSet.insert(*it2);
				++it2;
			}
			else
			{
				resultSet.insert(*it2);
				++it1;
				++it2;
			}
	}
	return resultSet;
}

int main()
{
	std::set<int> set1 = {};
	std::set<int> set2 = { 4, 5, 6 };

	set1 = mergeTwoSetsStl(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	set1 = mergeTwoSetsIter(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	set1 = { 1, 2, 3 };
	set2 = {};
	
	set1 = mergeTwoSetsStl(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	set1 = mergeTwoSetsIter(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	set1 = { 1, 2, 3 };
	set2 = { 4, 5, 6 };

	set1 = mergeTwoSetsStl(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	set1 = mergeTwoSetsIter(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	set1 = { 1, 3, 5, 7 };
	set2 = { 2, 4, 6, 8 };

	set1 = mergeTwoSetsStl(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	set1 = mergeTwoSetsIter(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	set1 = { 1, 2, 3 };
	set2 = { 3, 4, 5 };
	
	set1 = mergeTwoSetsStl(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	set1 = mergeTwoSetsIter(set1, set2);
	for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		std::cout << *it << " ";
	}
}