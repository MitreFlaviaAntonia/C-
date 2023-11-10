#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> findBall(std::vector<std::vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> answer(n, -1);

        for (int col = 0; col < n; col++)
        {
            int row = 0;
            int currCol = col;
            while (row < m) {
                if (grid[row][currCol] == 1)
                {
                    if (currCol + 1 < n && grid[row][currCol + 1] == 1)
                    {
                        currCol++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (currCol - 1 >= 0 && grid[row][currCol - 1] == -1)
                    {
                        currCol--;
                    }
                    else
                    {
                        break;
                    }
                }
                row++;
            }
            if (row == m)
            {
                answer[col] = currCol;
            }
        }

        return answer;
    }
};

int main()
{
    Solution solution;

    // Example test case
    std::vector<std::vector<int>> grid =
    {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {-1, -1, -1, 1, 1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1}
    };

    std::vector<int> result = solution.findBall(grid);

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

