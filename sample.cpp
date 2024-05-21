#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }

        visited[i][j] = true;

        grid[i][j] = '0';
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return ans;
    }
};
