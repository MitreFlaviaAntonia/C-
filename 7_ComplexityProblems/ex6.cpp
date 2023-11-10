#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

std::string sortString(std::string str)
{
    std::sort(str.begin(), str.end());
	return str;
}

int main()
{
    const int SIZE = 3; // Define the size of the array
	std::string strings[SIZE];

    // Input strings into the array
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> strings[i];
    }
    // Output the strings from the array
    std::cout << "Strings entered:" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        strings[i] = sortString(strings[i]);
        std::cout << strings[i] << std::endl;
    }

    std::sort(strings, strings + SIZE);
    
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << strings[i] << std::endl;
	}
    
	return 0;
}