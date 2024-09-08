#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int a = INT_MAX, b = INT_MIN, c = INT_MAX, d = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (!flag)
                    {
                        a = min(a,j);
                        b = max(b,j);
                        flag = true;
                    }
                    else
                    {
                        b = max(b,j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (grid[j][i] == 1)
                {
                    if (!flag)
                    {
                        c = min(c,j);
                        d = max(d,j);
                        flag = true;
                    }
                    else
                    {
                        d = max(d,j);
                    }
                }
            }
        }

        return (b - a + 1) * (d - c + 1);
    }
};
