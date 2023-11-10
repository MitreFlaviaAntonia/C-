#include <iostream>
#include <vector>

std::vector<int> countBits(int n)
{
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i / 2] + (i % 2);
    }

    return dp;
}

int main()
{
    int n = 5;
    std::vector<int> result = countBits(n);

    std::cout << "Count of 1's for each number from 0 to " << n << ":" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        std::cout << i << " --> " << result[i] << std::endl;
    }

    return 0;
}