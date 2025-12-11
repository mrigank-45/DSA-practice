// Q: You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell, 1 representing a fresh orange, or 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// ALGO: use BFS Concept, put all rotten in a queue, till queue is not empty, empty queue in each iteration and keep adding neighbours of rotten to the queue, when no neighbours is added, queue becomes empty, return ans.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;

        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0)
                    tot++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        // to get the 4 adjecent oranges
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            while (k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; ++i) // get adjecent oranges
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty())
                days++;
        }

        if (tot == cnt)
        {
            return days;
        }
        else
        {
            return -1;
        }
    }
};
