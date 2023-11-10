#include <iostream>
#include <fstream>
#include <vector>

bool isPalindrome(const std::vector<std::vector<int>>& matrix)
{
	int rowLength = matrix.size();
	int columnLength = matrix[0].size();

	for (int i = 0; i < rowLength; ++i)
	{
		for (int j = 0; j < columnLength; ++j)
		{
			if (matrix[i][j] != matrix[i][columnLength - 1 - j] || matrix[i][j] != matrix[rowLength - 1 - i][j] || matrix[i][j] != matrix[rowLength - 1 - i][columnLength - 1 - j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	std::ifstream file("excel.in");
	if (!file)
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	std::vector<std::vector<int>> matrix;
	int rowLength;
	int columnLength;
	file >> rowLength;
	file >> columnLength;

	for (int i = 0; i < rowLength; ++i)
	{
		std::vector<int> row;
		for (int j = 0; j < columnLength; ++j)
		{
			int element;
			file >> element;
			row.push_back(element);
		}
		matrix.push_back(row);
	}

	file.close();

	if (isPalindrome(matrix))
		std::cout << "The matrix read from the file is a palindrome matrix" << std::endl;
	else
		std::cout << "The matrix read from the file is not a palindrome matrix" << std::endl;

	return 0;
}