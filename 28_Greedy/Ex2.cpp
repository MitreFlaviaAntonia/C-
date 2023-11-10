/*#include <iostream>
#include <vector>

int matrixScore(std::vector<std::vector<int>>& grid)
{
	int rows = grid.size();
	int cols = grid[0].size();

	for (int row = 0; row < rows; row++)
	{
		if (grid[row][0] == 0)
		{
			for (int col = 0; col < cols; col++)
			{
				grid[row][col] = 1 - grid[row][col];
			}
		}
	}

	for (int col = 1; col < cols; col++)
	{
		int countZeros = 0;
		int countOnes = 0;
		for (int row = 0; row < rows; row++)
		{
			if (grid[row][col] == 0)
			{
				countZeros++;
			}
			else
			{
				countOnes++;
			}
		}
		if (countZeros > countOnes)
		{
			for (int row = 0; row < rows; row++)
			{
				grid[row][col] = 1 - grid[row][col];
			}
		}
	}

	int score = 0;
	for (int row = 0; row < rows; row++)
	{
		int rowValue = 0;
		for (int col = 0; col < cols; col++)
		{
			rowValue = (rowValue << 1) + grid[row][col];
		}
		score += rowValue;
	}

	return score;
}

int main()
{
	std::vector<std::vector<int>> grid1 = { {0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0} };
	int result1 = matrixScore(grid1);
	std::cout << "Highest possible score: " << result1 << std::endl;

	std::vector<std::vector<int>> grid2 = { {0} };
	int result2 = matrixScore(grid2);
	std::cout << "Highest possible score: " << result2 << std::endl;
}*/