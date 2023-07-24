#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid, int delrow[], int delcol[], int &count, bool &flag)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        // check for top, right, bottom, left
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                if ((nrow > 0) && (nrow < n - 1) && (ncol > 0) && (ncol < m - 1))
                {
                    count++;
                    dfs(nrow, ncol, vis, grid, delrow, delcol, count, flag);
                }
                else
                {
                    flag = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<pair<int, int>> one;
        vector<int> ans;
        ans.push_back(0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && (i > 0) && (i < n - 1) && (j > 0) && (j < m - 1))
                {
                    one.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < one.size(); i++)
        {
            if (!vis[one[i].first][one[i].second])
            {
                int count = 1;
                bool flag = false;
                dfs(one[i].first, one[i].second, vis, grid, delrow, delcol, count, flag);
                if (!flag)
                {
                    ans.push_back(count);
                }
            }
        }

        int max = *max_element(ans.begin(), ans.end());
        return max;
    }
};
