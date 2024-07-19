#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change_y_part(vector<vector<int>> &grid, int val, int n, int m)
    {
        int ans = 0;
        int i = 0, j = 0;
        while (i <= n / 2 && j <= m / 2)
        {
            if (grid[i][j] != val)
            {
                ++ans;
            }
            ++i;
            ++j;
        }

        i = 0;
        j = m - 1;
        while (i <= n / 2 && j >= m / 2)
        {
            if (grid[i][j] != val)
            {
                ++ans;
            }
            ++i;
            --j;
        }

        i = n / 2;
        j = n / 2;
        while (i < n)
        {
            if (grid[i][j] != val)
            {
                ++ans;
            }
            ++i;
        }

        if (grid[n / 2][m / 2] != val)
        {
            ans = ans - 2;
        }

        return ans;
    }
    int change_whole_grid(vector<vector<int>> &grid, int val, int n, int m)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] != val)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MAX;

        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                if(x == y) continue;
                int s1 = change_y_part(grid, x, n, m);
                int s2 = change_whole_grid(grid, y, n, m) - change_y_part(grid, y, n, m);

                cout<<"x: "<<x<<" y: "<<y<<" s1: "<<s1<<" s2: "<<s2<<endl;

                ans = min(ans, s1 + s2);
            }
        }
        return ans;
    }
};
