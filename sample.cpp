#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        map<int, int> row;
        map<int, int> col;
        vector<pair<int, int>> points;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                    points.push_back({i, j});
                }
            }
        }

        long long ans = 0;

        for (auto it : points)
        {
            int x = it.first;
            int y = it.second;

            if (row[x] == 0 || col[y] == 0)
                continue;

            ans += (row[x] - 1) * (col[y] - 1);
        }

        return ans;
    }
};
