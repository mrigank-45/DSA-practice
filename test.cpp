#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOutOfBounds(int i, int j, int n, int m)
    {
        return i < 0 || j < 0 || i >= n || j >= m;
    }
    int dfs(vector<vector<int>> grid, int i, int j)
    {
        if (grid[i][j] == 0)
        {
            return 0;
        }
        grid[i][j] = -1;

        int ans = 0;

        if (!isOutOfBounds(i + 1, j, grid.size(), grid[0].size()) && grid[i + 1][j] != -1 && grid[i + 1][j] != 0)
        {
            ans = max(ans, grid[i + 1][j] + dfs(grid, i + 1, j));
        }
        if (!isOutOfBounds(i - 1, j, grid.size(), grid[0].size()) && grid[i - 1][j] != -1 && grid[i - 1][j] != 0)
        {
            ans = max(ans, grid[i - 1][j] + dfs(grid, i - 1, j));
        }
        if (!isOutOfBounds(i, j + 1, grid.size(), grid[0].size()) && grid[i][j + 1] != -1 && grid[i][j + 1] != 0)
        {
            ans = max(ans, grid[i][j + 1] + dfs(grid, i, j + 1));
        }
        if (!isOutOfBounds(i, j - 1, grid.size(), grid[0].size()) && grid[i][j - 1] != -1 && grid[i][j - 1] != 0)
        {
            ans = max(ans, grid[i][j - 1] + dfs(grid, i, j - 1));
        }

        return ans;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    ans = max(ans, grid[i][j] + dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
