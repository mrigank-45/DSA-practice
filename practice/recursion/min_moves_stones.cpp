// Minimum Moves to Spread Stones Over Grid (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<pair<int, int>> zeros, vector<pair<int, int>> extras, vector<vector<int>> grid)
    {
        if (i >= zeros.size())
            return 0;

        int ans = INT_MAX;
        for (int j = 0; j < extras.size(); j++)
        {
            int x = extras[j].first, y = extras[j].second;
            if (grid[x][y] > 1)
            {
                grid[x][y]--;
                ans = min(ans, abs(zeros[i].first - x) + abs(zeros[i].second - y) + solve(i + 1, zeros, extras, grid));
                grid[x][y]++;
            }
        }
        return ans;
    }

    int minimumMoves(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> zeros, extras;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 0)
                    zeros.push_back({i, j});
                if (grid[i][j] > 1)
                    extras.push_back({i, j});
            }
        }

        if (zeros.size() == 0)
            return 0;
        return solve(0, zeros, extras, grid);
    }
};
