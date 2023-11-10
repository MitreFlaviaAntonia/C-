#include <iostream>
#include <set>

std::set<int> intersectionTwoSetsStl(std::set<int> set1, std::set<int> set2)
{
	if (set1.empty())
		return set1;

	if (set2.empty())
		return set2;

	auto it1 = set1.begin();
	auto it2 = set2.begin();

	std::set<int> resultSet;

	while (it1 != set1.end())
	{
		if (set2.find(*it1) != set2.end())
		{
			resultSet.insert(*it1);
		}	
		++it1;
	}

	return resultSet;
}

std::set<int> intersectionTwoSetsIter(std::set<int> set1, std::set<int> set2)
{
	if (set1.empty())
		return set1;

	if (set2.empty())
		return set2;

	auto it1 = set1.begin();
	auto it2 = set2.begin();

	std::set<int> resultSet;
	
	while (it1 != set1.end())
	{
		if (*it1 < *it2)
		{
			++it1;
		}
		else
			if (*it1 > *it2)
			{
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
	std::set<int> set1 = { 1, 2, 3 };
	std::set<int> set2 = { 1, 3, 4, 5 };

	set1 = intersectionTwoSetsStl(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;

	
	set1 = intersectionTwoSetsIter(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;

	set1 = { 1, 2, 3 };
	set2 = { 4, 5, 6 };

	set1 = intersectionTwoSetsStl(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;


	set1 = intersectionTwoSetsIter(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;

	set1 = { 1, 2, 3 };
	set2 = {};

	set1 = intersectionTwoSetsStl(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;


	set1 = intersectionTwoSetsIter(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;

	set1 = {};
	set2 = { 4, 5, 6 };

	set1 = intersectionTwoSetsStl(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;


	set1 = intersectionTwoSetsIter(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;

	set1 = { 1, 2, 3 };
	set2 = { 1, 2, 3 };

	set1 = intersectionTwoSetsStl(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}

	std::cout << std::endl;


	set1 = intersectionTwoSetsIter(set1, set2);
	if (set1.empty())
	{
		std::cout << "No common elements";
	}
	else
		for (std::set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
		{
			std::cout << *it << " ";
		}
}