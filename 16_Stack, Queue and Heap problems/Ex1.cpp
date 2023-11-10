#include<iostream>
#include <cstring>
#include <stack>

bool matchingParanthesis(std::string par)
{
	bool isValid = false;
	std::stack<char> charStack;

	char p = '\0';

	int searchIndex = -1;
	for (int i = 0; i < par.size(); i++)
	{
		if (par[i] == '(' || par[i] == '[' || par[i] == '{')
		{
			charStack.push(par[i]);
			searchIndex = i;
		}
	}

	searchIndex++;

	if (charStack.empty())
	{
		return false;
	}
	bool isMatching = false;
	int i;

	while (!charStack.empty())
	{
		p = charStack.top();

		for (i = searchIndex; i < par.size(); i++)
		{
			if ((p == '(' && par[i] == ')') || (p == '[' && par[i] == ']') || (p == '{' && par[i] == '}'))
			{
				isMatching = true;
				searchIndex = i + 1;
				break;
			}

			if ((p == '(' && (par[i] == ']' || par[i] == '}')) || (p == '[' && (par[i] == ')' || par[i] == '}')) || (p == '{' && (par[i] == ')' || par[i] == ']')))
			{
				return false;
			}
		}

		if (isMatching == true)
		{
			isValid = true;
		}
		else
		{
			return false;
		}

		charStack.pop();
	}

	return isValid;
}

int main()
{
	std::string par1 = "[aaaa{xx(xx)}cc]";
	std::string par2 = "([)]";

	if (matchingParanthesis(par1))
	{
		std::cout << "Valid." << std::endl;
	}
	else
	{
		std::cout << "Invalid." << std::endl;
	}

	if (matchingParanthesis(par2))
	{
		std::cout << "Valid." << std::endl;
	}
	else
	{
		std::cout << "Invalid." << std::endl;
	}

	return 0;
}