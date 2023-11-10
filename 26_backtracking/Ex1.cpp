#include <iostream>
#include <vector>
#include <string>

void printVectorOfStrings(const std::vector<std::string>& vec)
{
	for (const auto& innerVec : vec)
	{
		for (const auto& element : innerVec)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}

bool foundSolution(int digitsSize, std::string sol)
{
	return digitsSize == sol.size();
}

void backtracking(std::string digits, std::vector<std::vector<char>>& telBtnLetters, std::string sol, std::vector<std::string>& result, int digitsSize, int digitsIndex)
{
	if (foundSolution(digitsSize, sol))
	{	
		result.push_back(sol);
	}
	else
	{
		int currentDigitInt = digits[digitsIndex] - '0';
		for (int j = 0; j < telBtnLetters[currentDigitInt].size(); j++)
		{
			sol.push_back(telBtnLetters[currentDigitInt][j]);
			backtracking(digits, telBtnLetters, sol, result, digitsSize, digitsIndex + 1);
			sol.pop_back();
		}
	}
}

std::vector<std::string> letterCombinations(std::string digits)
{
	if (digits.empty())
	{
		return {};
	}

	std::vector<std::vector<char>> telBtnLetters(10);
	char letter = 'a';
	for (int digit = 2; digit <= 9; digit++)
	{
		if (digit != 9 && digit != 7)
		{
			telBtnLetters[digit].push_back(letter);
			telBtnLetters[digit].push_back(letter + 1);
			telBtnLetters[digit].push_back(letter + 2);
			letter = letter + 3;
		}
		else
		{
			telBtnLetters[digit].push_back(letter);
			telBtnLetters[digit].push_back(letter + 1);
			telBtnLetters[digit].push_back(letter + 2);
			telBtnLetters[digit].push_back(letter + 3);
			letter = letter + 4;
		}
	}

	std::vector<std::string> result;
	std::string addInResult;
	backtracking(digits, telBtnLetters, addInResult, result, digits.size(), 0);
	return result;
}

int main()
{
	std::string digits = "23";
	std::cout << "solutions: " << std::endl;
	printVectorOfStrings(letterCombinations(digits));
	return 0;
}