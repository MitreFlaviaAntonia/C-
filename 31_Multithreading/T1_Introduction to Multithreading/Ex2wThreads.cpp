#include <iostream>
#include <vector>
#include <thread>
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

// Function to multiply a row of the first matrix with a column of the second matrix
int multiplyRowColumn(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, int row, int col)
{
	int result = 0;
	for (int i = 0; i < matrix1[row].size(); ++i)
	{
		result += matrix1[row][i] * matrix2[i][col];
	}
	return result;
}

// Function to perform matrix multiplication using threads
void matrixMultiply(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result)
{
	int rows = matrix1.size();
	int cols = matrix2[0].size();

	std::vector<std::thread> threads(rows);

	// Create threads to perform multiplication
	for (int i = 0; i < rows; ++i)
	{
		threads[i] = std::thread([i, &matrix1, &matrix2, &result, cols]()
			{
				for (int j = 0; j < cols; ++j)
				{
					int temp = 0;
					for (int k = 0; k < matrix1[i].size(); ++k)
					{
						temp += matrix1[i][k] * matrix2[k][j];
					}
					result[i][j] = temp;
				}
			});
	}

	// Wait for all threads to finish
	for (auto& thread : threads)
	{
		thread.join();
	}
}

int main()
{
	int rows1 = 20;
	int cols1 = 30;
	int cols2 = 20;

	std::vector<std::vector<int>> matrix1 = generateRandomMatrix(rows1, cols1);
	std::vector<std::vector<int>> matrix2 = generateRandomMatrix(cols1, cols2);

	std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix2[0].size()));

	auto start = std::chrono::high_resolution_clock::now();  // Start the timer

	matrixMultiply(matrix1, matrix2, result);

	auto end = std::chrono::high_resolution_clock::now();  // Stop the timer

	std::chrono::duration<double, std::milli> duration = end - start;  // Calculate the duration

	std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[0].size(); ++j)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
} // time = 7 milliseconds