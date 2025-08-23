#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> maxRow(n, 0);
        vector<int> maxCol(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }

        int increase = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = min(maxRow[i], maxCol[j]);
                if(temp > grid[i][j]) {
                    increase += (temp - grid[i][j]);
                }
            }
        }
        return increase;
    }
};
