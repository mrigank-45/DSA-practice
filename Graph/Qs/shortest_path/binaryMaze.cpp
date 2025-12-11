// Shortest path in binary maze(leetcode): use dijkstra algo

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dx[8] = {0, 1, -1, 0, 1, -1, -1, 1};
    int dy[8] = {1, 0, 0, -1, 1, -1, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for (int k = 0; k <= 7; k++)
            {
                int newx = x + dx[k];
                int newy = y + dy[k];
                if (newx < 0 or newy < 0 or newx >= n or newy >= n or grid[newx][newy] == 1)
                    continue;
                if (dist[newx][newy] > 1 + dis)
                {
                    dist[newx][newy] = 1 + dis;
                    pq.push({dist[newx][newy], {newx, newy}});
                }
            }
        }
        if (dist[n - 1][n - 1] == 1e9)
        {
            return -1;
        }
        else
        {
            return dist[n - 1][n - 1];
        }
    }
};
