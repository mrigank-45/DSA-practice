#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<string> row, col;

        for (int i = 0; i < n; i++)
        {
            string r = "", c = "";
            for (int j = 0; j < n; j++)
            {
                r += to_string(grid[i][j]);
                r += '_';
            }
            row.push_back(r);
        }

        for (int i = 0; i < n; i++)
        {
            string c = "";
            for (int j = 0; j < n; j++)
            {
                c += to_string(grid[j][i]);
                c += '_';
            }
            col.push_back(c);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string r = row[i];
                string c = col[j];

                if (r == c)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
