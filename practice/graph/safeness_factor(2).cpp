#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // func1 to calculate minimum distance for each cell by starting from 1
    vector<vector<int>> min_distance_from1(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else
                    grid[i][j] = INT_MAX;
            }
        }
        int row[4] = {-1, 1, 0, 0}, col[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first, y = top.second, time = grid[x][y];
            for (int i = 0; i < 4; i++)
            {
                int newx = x + row[i], newy = y + col[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == INT_MAX)
                {
                    grid[newx][newy] = time + 1;
                    q.push({newx, newy});
                }
            }
        }
        return grid;
    }

    int solve(int i, int j, int &n, vector<vector<int>> &cost, vector<vector<bool>> &vis, int &mid)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || cost[i][j] < mid || vis[i][j])
            return false;
        if (i == n - 1 && j == n - 1)
        {
            return cost[i][j] >= mid;
        }
        vis[i][j] = true;
        bool ans = false;
        if (cost[i][j] >= mid)
        {
            ans |= solve(i + 1, j, n, cost, vis, mid);
            ans |= solve(i - 1, j, n, cost, vis, mid);
            ans |= solve(i, j + 1, n, cost, vis, mid);
            ans |= solve(i, j - 1, n, cost, vis, mid);
        }
        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> cost = min_distance_from1(grid);

        int low = 0, high = n, mid, ans = -1;
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (solve(0, 0, n, cost, vis, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
