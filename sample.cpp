#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &energy, int k, int n, int i, int choose, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return choose == 1 ? 0 : INT_MIN;
        }

        if (dp[i][choose] != INT_MIN)
        {
            return dp[i][choose];
        }

        if (choose == 1)
        {
            dp[i][choose] = energy[i] + solve(energy, k, n, i + k, 1, dp);
        }
        else
        {
            int take = energy[i] + solve(energy, k, n, i + k, 1, dp);
            int skip = solve(energy, k, n, i + 1, 0, dp);
            dp[i][choose] = max(take, skip);
        }

        return dp[i][choose];
    }

    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        return solve(energy, k, n, 0, 0, dp);
    }
};
