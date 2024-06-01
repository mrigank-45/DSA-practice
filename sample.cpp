#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOutOfBounds(int i, int j, int n, int m)
    {
        return i < 0 || j < 0 || i >= n || j >= m;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0) {
            return 0;
        }
        
        int gold = grid[i][j];
        grid[i][j] = 0;
        
        int maxGold = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (auto& dir : directions) {
            int new_i = i + dir.first;
            int new_j = j + dir.second;
            
            if (!isOutOfBounds(new_i, new_j, grid.size(), grid[0].size()) && grid[new_i][new_j] != 0) {
                maxGold = max(maxGold, dfs(grid, new_i, new_j));
            }
        }
        
        grid[i][j] = gold; 
        return maxGold + gold;
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
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
