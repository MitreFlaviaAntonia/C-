#include <iostream>
#include <list>
#include <queue>

std::list<int> mergeKSortedLists(std::list<std::list<int>>& lists)
{
	std::priority_queue<int> minHeap;

	for (auto listsIt = lists.begin(); listsIt != lists.end(); ++listsIt)
	{
		for (auto valIt = listsIt->begin(); valIt != listsIt->end(); ++valIt)
		{
			if (!listsIt->empty())
			{
				minHeap.push(*valIt);
			}
		}
	}

	std::list<int> mergedList;

	while (!minHeap.empty())
	{
		mergedList.push_front(minHeap.top());
		minHeap.pop();
	}

	return mergedList;
}

int main()
{
	std::list<std::list<int>> lists = { {1, 4, 7}, {2, 5, 8}, {3, 6, 9} };

	std::list<int> mergedList = mergeKSortedLists(lists);

	for (auto it = mergedList.begin(); it != mergedList.end(); ++it)
	{
		std::cout << *it << " ";
	}

	return 0;
}
