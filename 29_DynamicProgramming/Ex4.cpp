#include <iostream>
#include <vector>

bool divisorGame(int n)
{
    std::vector<bool> dp(n + 1, false);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0 && !dp[i - j])
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{
    int n = 2;
    bool result = divisorGame(n);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}