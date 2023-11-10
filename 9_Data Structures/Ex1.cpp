#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int n;
    int element;
    std::cout << "How many numbers are in the vector? ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "numbers[" << i << "]= ";
        std::cin >> element;
        numbers.push_back(element);
    }
    int x;
	std::cout << "Enter an element to insert at the same position as it's value: ";
	std::cin >> x;

    if (x > numbers.size())
    {
        std::cout << "Index is out of bounds.";
    }
    else
    {
		numbers.insert(numbers.begin() + x, x);
        for (int i : numbers)
		{
			std::cout << i << " ";
		}
    }
	
    return 0;
}