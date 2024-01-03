// Find the Safest Path in a Grid (Leetcode)
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

    // func2 to find length of path minimizing the distance
    int max_min_path(vector<vector<int>> &A)
    {
        const int M = A.size();
        const int N = A[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({A[0][0], {0, 0}});
        A[0][0] = -1;

        while (!pq.empty())
        {
            int score = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == M - 1 && y == N - 1)
                return score;

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];

                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == -1)
                    continue;

                pq.push({min(score, A[a][b]), {a, b}});
                A[a][b] = -1;
            }
        }

        return -1;
    }

    // alternate func2 to find ans but gives TLE
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

    int maximumSafenessFactor(vector<vector<int>> &mat)
    {
        vector<vector<int>> ans = min_distance_from1(mat);

        return max_min_path(ans);
    }
};
