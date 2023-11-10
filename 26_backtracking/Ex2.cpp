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

void backtracking(const std::string& paranthesis, std::string& sol, std::vector<std::string>& result, int n, int openCount, int closeCount)
{
	if (sol.size() == n * 2)
	{
		result.push_back(sol);
	}
	else
	{
		if (openCount < n)
		{
			sol.push_back('(');
			backtracking(paranthesis, sol, result, n, openCount + 1, closeCount);
			sol.pop_back();
		}
		if (closeCount < openCount)
		{
			sol.push_back(')');
			backtracking(paranthesis, sol, result, n, openCount, closeCount + 1);
			sol.pop_back();
		}
	}
}

std::vector<std::string> generateParenthesis(int n)
{
	std::vector<std::string> result;
	std::string paranthesis(2 * n, ' ');
	std::string sol;
	backtracking(paranthesis, sol, result, n, 0, 0);
	return result;
}

int main()
{	
	int n = 4;
	std::cout << "solutions: " << std::endl;
	printVectorOfStrings(generateParenthesis(n));
	return 0;
}