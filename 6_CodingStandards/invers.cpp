#include <iostream>
#include <fstream>
#include <string>

std::string reverseString(const std::string& str)
{
	std::string reversedStr = str;

	int start = 0;
	int end = reversedStr.length() - 1;

	while (start < end)
	{

		char temp = reversedStr[start];
		reversedStr[start] = reversedStr[end];
		reversedStr[end] = temp;
		start++;
		end--;
	}

	return reversedStr;
}

int findMaxWordLength(std::string fileName)
{
	std::fstream file;
	std::string word;
	int maxWordLength = 0;
	file.open(fileName.c_str());
	while (file >> word)
	{
		if (size(word) > maxWordLength)
		{
			maxWordLength = size(word);
		}
	}
	if (!file.eof())
	{
		std::cout << "Error reading file." << std::endl;
	}
	file.close();
	return maxWordLength;
}

void reverseMaxLengthWordsFromFile(int maxWordLength, std::string inFileName, std::string outFileName)
{
	std::fstream inputFile;
	std::ofstream outputFile;
	std::string word;
	inputFile.open(inFileName.c_str());
	while (inputFile >> word)
	{
		if (size(word) > maxWordLength)
		{
			outputFile << reverseString(word) << ' ';
		}
		else
		{
			outputFile << word << ' ';
		}
		outputFile << reverseString(word) << ' ';
	}
	if (!inputFile.eof())
	{
		std::cout << "Error reading file." << std::endl;
	}
	inputFile.close();
	outputFile.close();
}

int main()
{
	std::string inFileName = "excel.in";
	std::string outFileName = "excel.out";
	int maxWordLength = findMaxWordLength(inFileName);
	reverseMaxLengthWordsFromFile(maxWordLength, inFileName, outFileName);
	return 0;
}