#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distance(n, vector<int>(m, -2));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        int count = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                if (x < 0 || y < 0 || x >= n || y >= m || distance[x][y] != -2 || grid[x][y] == -1)
                {
                    continue;
                }

                distance[x][y] = count;

                q.push({x + 1, y});
                q.push({x - 1, y});
                q.push({x, y + 1});
                q.push({x, y - 1});
            }
            count++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (distance[i][j] != -2)
                {
                    grid[i][j] = distance[i][j];
                }
            }
        }
    }
};
