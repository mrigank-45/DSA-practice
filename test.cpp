#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[2001][2001];
    int solve(int n, int curr, int temp)
    {
        if (curr > n)
        {
            return INT_MAX;
        }

        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][temp] != -1)
        {
            return dp[curr][temp];
        }

        // Copy
        int copySteps = INT_MAX;
        if (curr != temp)
        {
            copySteps = 1 + solve(n, curr, curr);
        }

        // Paste
        int pasteSteps = 1 + solve(n, curr + temp, temp);

        dp[curr][temp] = min(copySteps, pasteSteps);

        return dp[curr][temp];
    }

    int minSteps(int n)
    {
        memset(dp, -1, sizeof(dp));

        return solve(n, 1, 0);
    }
};
