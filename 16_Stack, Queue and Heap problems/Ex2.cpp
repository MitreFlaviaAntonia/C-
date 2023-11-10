#include <iostream>
#include <list>
#include <queue>

void printList(const std::list<int>& myList)
{
	for (const auto& element : myList)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

std::list<int> createNumberList(int maxVal, int firstNum, int incr1, int incr2)
{
	std::list<int> numList;
	std::queue<int> queue1;
	std::queue<int> queue2;

	bool oob1 = false;
	bool oob2 = false;
	int q1 = firstNum + incr1;
	queue1.push(q1);
	int q2 = firstNum + incr2;
	queue2.push(q2);
	int nextVal = 0;
	numList.push_back(firstNum);

	while (!queue1.empty() && !queue2.empty())
	{
		if (queue1.front() < queue2.front())
		{
			nextVal = queue1.front();
			if (queue1.front() + incr1 <= maxVal)
			{
				queue1.push(queue1.front() + incr1);
			}
			else
			{
				oob1 = true;
			}

			if (queue1.front() + incr2 <= maxVal)
			{
				queue2.push(queue1.front() + incr2);
			}
			else
			{
				oob2 = true;
			}
			queue1.pop();
		}
		else if (queue2.front() < queue1.front())
		{
			nextVal = queue2.front();
			if (queue2.front() + incr1 <= maxVal)
			{
				queue1.push(queue2.front() + incr1);
			}
			else
			{
				oob1 = true;
			}

			if (queue2.front() + incr2 <= maxVal)
			{
				queue2.push(queue2.front() + incr2);
			}
			else
			{
				oob2 = true;
			}

			queue2.pop();
		}
		else
		{
			nextVal = queue1.front();
			if (queue1.front() + incr1 <= queue2.front() + incr1)
			{
				if (queue1.front() + incr1 <= maxVal)
				{
					queue1.push(queue1.front() + incr1);
				}
				else
				{
					oob1 = true;
				}
			}
			else
			{
				if (queue2.front() + incr1 <= maxVal)
				{
					queue1.push(queue2.front() + incr1);
				}
				else
				{
					oob2 = true;
				}
			}
			queue1.pop();
			queue2.pop();
		}
		if (nextVal > maxVal)
			break;

		numList.push_back(nextVal);
	}

	if (oob1)
	{
		while (!queue1.empty())
		{
			numList.push_back(queue1.front());
			queue1.pop();
		}
	}

	if (oob2)
	{
		while (!queue2.empty())
		{
			numList.push_back(queue2.front());
			queue2.pop();
		}
	}

	return numList;
}

int main()
{
	int maxVal;
	std::cout << "Enter the maximum value that can be in the list : " << std::endl;
	std::cin >> maxVal;
	int firstNum;
	std::cout << "Enter the starting number from the list: " << std::endl;
	std::cin >> firstNum;
	int incr1;
	std::cout << "Enter the first increasing value: " << std::endl;
	std::cin >> incr1;
	int incr2;
	std::cout << "Enter the second increasing value: " << std::endl;
	std::cin >> incr2;

	printList(createNumberList(maxVal, firstNum, incr1, incr2));

	return 0;
}