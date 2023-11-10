#include <iostream>
#include <fstream>
#include <map>

int main()
{
	std::ifstream inFile("input.in");

	int nrStrings;
	std::cout << "How many strings do you want to read from the file?" << std::endl;
	std::cin >> nrStrings;

	std::map<std::string, int> freqMap;

	for (int i = 0; i < nrStrings; ++i)
	{
		std::string word;
		inFile >> word;
		++freqMap[word];
	}

	for (const auto& word : freqMap)
	{
		std::cout << "The frequency of " << word.first << " is " << word.second << '\n';
	}

	inFile.close();

	return 0;
}