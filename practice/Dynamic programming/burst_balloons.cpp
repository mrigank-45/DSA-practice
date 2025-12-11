// Burst Balloons
// can solve using other dp approach but will give TLE even in memorization

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(vector<int> &v, vector<vector<int>> &dp, int i, int j)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            // The balloons at v[i-1] and v[j+1] are considered as the adjacent balloons after all balloons between i and j are burst.
            int num = v[i - 1] * v[k] * v[j + 1] + func(v, dp, i, k - 1) + func(v, dp, k + 1, j);
            ans = max(ans, num);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int> &v)
    {
        int n = v.size();
        v.push_back(1);
        v.insert(v.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // Computes the maximum coins that can be obtained by bursting balloons between indices i and j (i and j inclusive).
        return func(v, dp, 1, n);
    }
};
