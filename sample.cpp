#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveColumn(int n, int m, vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k = n - j - 1;
                if (k <= j)
                    break;
                if (grid[j][i] != grid[k][i])
                    ans++;
            }
        }
        return ans;
    }
    int solveRow(int n, int m, vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = m - j - 1;
                if (k <= j)
                    break;
                if (grid[i][j] != grid[i][k])
                    ans++;
            }
        }
        return ans;
    }
    int minFlips(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        return min(solveRow(n, m, grid), solveColumn(n, m, grid));
    }
};
