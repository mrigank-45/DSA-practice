#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

    void solve(vector<vector<int>> &updatedGrid, int x, int y, int mini, vector<int> &maxi, map<pair<int, int>, bool> visited)
    {
        if (x < 0 || y < 0 || x >= updatedGrid.size() || y >= updatedGrid[0].size())
        {
            return;
        }

        if (x == updatedGrid.size() - 1 && y == updatedGrid[0].size() - 1)
        {
            maxi.push_back(min(updatedGrid[x][y], mini));

            return;
        }

        visited[{x, y}] = true;

        mini = min(mini, updatedGrid[x][y]);

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= updatedGrid.size() || ny >= updatedGrid[0].size() || visited[{nx, ny}])
            {
                continue;
            }
            else
            {
                solve(updatedGrid, nx, ny, mini, maxi, visited);
            }
        }

        return;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        vector<vector<int>> updatedGrid = min_distance_from1(grid);
        vector<int> maxi;
        map<pair<int, int>, bool> visited;

        solve(updatedGrid, 0, 0, INT_MAX, maxi, visited);

        int ans = INT_MIN;
        for (int i = 0; i < maxi.size(); i++)
        {
            ans = max(ans, maxi[i]);
        }

        return ans;
    }
};
