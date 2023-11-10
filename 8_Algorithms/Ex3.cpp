#include <iostream>

int main()
{
	int length;
	std::cout << "How many numbers do you want to read? ";
	std::cin >> length;
	int next;
	int mid;
	int prev;
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		std::cout << "number " << i << " is: ";
		std::cin >> next;

		if (i == 0)
		{
			prev = next;
		}

		if (i == 1)
		{
			mid = next;
		}

		if (i >= 2 && i < length)
		{
			if (prev < mid && mid > next)
			{
				sum = sum + mid;
			}
			prev = mid;
			mid = next;
		}
	}

	std::cout << sum;

	return 0;
}