// Dice Throw (gfg)
// Q based on distinct ways

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MOD 1000000007
    long long solveRec(int dices, int faces, int target)
    {
        // base cases
        if (target < 0)
            return 0;
        if (dices == 0 && target != 0)
            return 0;
        if (dices != 0 && target == 0)
            return 0;

        if (dices == 0 && target == 0)
            return 1;

        int ans = 0;

        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solveRec(dices - 1, faces, target - i);
        }
        return ans;
    }

    long long solveMem(int dices, int faces, int target, vector<vector<long long>> &dp)
    {
        // base cases
        if (target < 0)
            return 0;
        if (dices == 0 && target != 0)
            return 0;
        if (dices != 0 && target == 0)
            return 0;

        if (dices == 0 && target == 0)
            return 1;

        if (dp[dices][target] != -1)
            return dp[dices][target];

        long long ans = 0;

        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solveMem(dices - 1, faces, target - i, dp);
        }
        return dp[dices][target] = ans;
    }

    int solveTab(int dices, int faces, int target)
    {
        vector<vector<long long>> dp(dices + 1, vector<long long>(target + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= dices; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                long long ans = 0;

                for (int k = 1; k <= faces; k++)
                {
                    if (j - k >= 0 && dices - 1 >= 0)
                    {
                        ans = (ans + dp[i - 1][j - k]) % MOD;
                    }
                }

                dp[i][j] = ans;
            }
        }

        return dp[dices][target] % MOD;
    }

    long long solveSpaceOptimised(int n, int k, int t)
    {
        vector<long long> prev(t + 1, 0);
        vector<long long> curr(t + 1, 0);

        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (target - i >= 0)
                        ans = ans + prev[target - i];
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return prev[t];
    }

    long long noOfWays(int M, int N, int X)
    {
        // code here
        return solveSpaceOptimised(N, M, X);
    }
};
