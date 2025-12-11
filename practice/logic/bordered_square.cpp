#include <bits/stdc++.h>
using namespace std;

// Largest 1-Bordered Square (Leetcode)
// We need to get a frame with the largest 'a' possible, lets consider each cell as left-top corner of that frame.

class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                    continue;

                // find max 'a' possible with this corner
                int curMaxSize = min(m - i, n - j);
                for (int curI = i; curI < i + curMaxSize; curI++)
                {
                    if (!grid[curI][j])
                    {
                        curMaxSize = curI - i;
                        break;
                    }
                }
                for (int curJ = j; curJ < j + curMaxSize; curJ++)
                {
                    if (!grid[i][curJ])
                    {
                        curMaxSize = curJ - j;
                        break;
                    }
                }

                // check if we can get a frame with size 'a' or less
                for (int a = curMaxSize; a > res; a--)
                {
                    int maxI = i + a - 1;
                    int maxJ = j + a - 1;
                    bool valid = true;
                    for (int curI = i; valid && curI <= maxI; curI++)
                    {
                        if (!grid[curI][maxJ])
                        {
                            valid = false;
                        }
                    }
                    for (int curJ = j; valid && curJ <= maxJ; curJ++)
                    {
                        if (!grid[maxI][curJ])
                        {
                            valid = false;
                        }
                    }
                    if (valid)
                        res = a;
                }
            }
        }
        return res * res;
    }
};
