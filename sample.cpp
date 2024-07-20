#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int x1, int x2, int y1, int y2, vector<int> &horizontalCut, vector<int> &verticalCut, vector<vector<vector<vector<int>>>> &dp)
    {
        if (x1 > x2 || y1 > y2)
            return 0;
        if (x1 == x2 && y1 == y2)
            return 0;

        if (dp[x1][x2][y1][y2] != -1)
            return dp[x1][x2][y1][y2];

        int min_cost = INT_MAX;

        for (int cut = x1; cut < x2; ++cut)
        {
            int cost = horizontalCut[cut] +
                       rec(x1, cut, y1, y2, horizontalCut, verticalCut, dp) +
                       rec(cut + 1, x2, y1, y2, horizontalCut, verticalCut, dp);
            min_cost = min(min_cost, cost);
        }

        for (int cut = y1; cut < y2; ++cut)
        {
            int cost = verticalCut[cut] +
                       rec(x1, x2, y1, cut, horizontalCut, verticalCut, dp) +
                       rec(x1, x2, cut + 1, y2, horizontalCut, verticalCut, dp);
            min_cost = min(min_cost, cost);
        }

        dp[x1][x2][y1][y2] = min_cost;
        return min_cost;
    }

    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1))));
        return rec(0, m - 1, 0, n - 1, horizontalCut, verticalCut, dp);
    }
};
