/*#include <iostream>
#include <cmath>
#include <vector>
#include <list>
using namespace std;

//https://leetcode.com/problems/super-pow/
vector<int> divider(vector<int> b)
{
	int n = b.size();
	for (int i = 0; i < n; i++)
	{
		if (b[i] % 2 == 1 && i < n - 1)
		{
			b[i + 1] += 10;
		}

		b[i] = b[i] / 2;
	}

	int k = 0;

	while (k < n && b[k] == 0)
	{
		k++;
	}
	b.erase(b.begin(), b.begin() + k);

	return b;
}

int superPow(int a, vector<int> b)
{
	int index = b.size() - 1;
	if (b.empty())
		return 1;

	if (b[index] % 2 == 0)
	{
		int res = superPow(a, divider(b));
		return (res * res) % 1337;
	}
	else
	{
		int res = superPow(a, divider(b));
		return (a * res * res) % 1337;
	}
}

int main()
{
	int a = 1;
	vector<int> b = { 4,3,3,8,5,2 };
	cout << superPow(a, b);

	return 0;
}*/