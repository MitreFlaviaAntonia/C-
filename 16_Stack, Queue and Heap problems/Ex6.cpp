#include <iostream>
#include <vector>
#include <stack>

std::string eliminateLeadingZeros(std::string num)
{
	bool firstDigitFound = false;
	int cntLeadingZeros = 0;

	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] != '0')
		{
			firstDigitFound = true;
		}

		if (firstDigitFound)
		{
			break;
		}

		if (num[i] == '0' && firstDigitFound == false)
		{
			cntLeadingZeros++;
		}
	}

	if (firstDigitFound == false)
	{
		return "0";
	}

	if (cntLeadingZeros != 0)
	{
		num = num.substr(cntLeadingZeros);
	}
	
	return num;
}

std::string removeKdigits(std::string num, int k)
{
	if (k == 0)
	{
		return num;
	}

	int size = num.size();

	if (k >= size)
	{
		return "0";
	}

	std::stack<char> digitsStack;
	
	digitsStack.push(num[0]);
	
	for(int i = 1; i < size ; i++)
	{
		while (!digitsStack.empty() && digitsStack.top() > num[i] && k != 0)
		{
			if (k == 0)
			{
				break;
			}
			
			digitsStack.pop();
			k--;
		}

		digitsStack.push(num[i]);
	}
	while (k != 0 && !digitsStack.empty())
	{
		digitsStack.pop();
		k--;
	}

	std::string str;
	
	while (!digitsStack.empty())
	{
		str += digitsStack.top();
		digitsStack.pop();
	}

	std::reverse(str.begin(), str.end());

	if (str[0] == '0' && str.size() > 1)
	{
		str = eliminateLeadingZeros(str);
	}

	return str;
}


int main()
{
	std::string num = "1234567890";
	int k = 9;
	std::string result;
	result = removeKdigits(num, k);
	std::cout << result << std::endl;
}