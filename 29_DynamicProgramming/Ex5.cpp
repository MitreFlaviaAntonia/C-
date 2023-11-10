#include <iostream>
#include <vector>

class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                if (dp[i - coin] != std::numeric_limits<int>::max())
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
    }
};

int main()
{
    Solution solution;

    std::vector<int> coins = { 1, 2, 5 };
    int amount = 11;
    int result = solution.coinChange(coins, amount);
    std::cout << "Result: " << result << std::endl;

    return 0;
}