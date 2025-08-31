#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        int n = grid.size();
        int m = grid[0].size();

        int curr = grid[row][col];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        vector<pair<int, int>> borders;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                bool flag = false;
                for (auto dir : directions)
                {
                    int newRow = r + dir[0], newCol = c + dir[1];
                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != curr)
                    {
                        flag = true;
                        continue;
                    }
                    if (!visited[newRow][newCol])
                    {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
                if (flag)
                {
                    borders.push_back({r, c});
                }
            }
        }
        for (auto border : borders)
        {
            grid[border.first][border.second] = color;
        }
        return grid;
    }
};
