#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = dis(gen);
		}
	}

	return matrix;
}

// Function to perform matrix multiplication
std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2)
{
	int rows1 = matrix1.size();
	int cols1 = matrix1[0].size();
	int cols2 = matrix2[0].size();

	std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

	for (int i = 0; i < rows1; ++i)
	{
		for (int j = 0; j < cols2; ++j)
		{
			for (int k = 0; k < cols1; ++k)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return result;
}

int main()
{
	int rows1 = 20;
	int cols1 = 30;
	int cols2 = 20;

	std::vector<std::vector<int>> matrix1 = generateRandomMatrix(rows1, cols1);
	std::vector<std::vector<int>> matrix2 = generateRandomMatrix(cols1, cols2);

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	std::vector<std::vector<int>> result = matrixMultiplication(matrix1, matrix2);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer

	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	std::cout << "Matrix multiplication result:" << std::endl;
	for (const auto& row : result)
	{
		for (const auto& element : row)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}

	

	return 0;
} // time = 22 milliseconds