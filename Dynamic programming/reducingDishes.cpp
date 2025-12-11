#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion + memorization
    int solve(vector<int> &sat, vector<vector<int>> &dp, int index, int t)
    {
        if (index == sat.size())
            return 0;

        if (dp[index][t] != -1)
            return dp[index][t];

        int excluded = solve(sat, dp, index + 1, t);                      // when we don't include the indexent index
        int included = sat[index] * t + solve(sat, dp, index + 1, t + 1); // when we include the indexent index

        dp[index][t] = max(included, excluded);
        return dp[index][t];
    }

    // tabulation
    int solve1(vector<int> &sat)
    {
        int n = sat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 1; time--)
            {
                int excluded = dp[index + 1][time];
                int included = sat[index] * time + dp[index + 1][time + 1];
                dp[index][time] = max(included, excluded);
            }
        }

        return dp[0][1];
    }

    // space optamization
    int solve2(vector<int> &sat)
    {
        int n = sat.size();
        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 1; time--)
            {
                int excluded = next[time];
                int included = sat[index] * time + next[time + 1];
                curr[time] = max(included, excluded);
                next = curr;
            }
        }

        return next[1];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        // first sort the vector
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(satisfaction, dp, 0, 1);
    }
};
