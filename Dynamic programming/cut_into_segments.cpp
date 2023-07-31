// Cut into segments (codeStudio)

#include <bits/stdc++.h>
using namespace std;

// recursion
int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    // The answer for 'N' is max of all three recursive call.
    return max(a, max(b, c));
}

// recursion + memorization
int solve1(int n, int x, int y, int z, vector<int> dp)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = solve1(n - x, x, y, z, dp) + 1;
    int b = solve1(n - y, x, y, z, dp) + 1;
    int c = solve1(n - z, x, y, z, dp) + 1;

    // The answer for 'N' is max of all three recursive call + 1.
    dp[n] = max(a, max(b, c));
    return dp[n];
}

// tabulation
int solve2(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        // Checking if 'i' greater than 'X' and if 'i - X' length rod can be cut into segments.
        if (i - x >= 0 && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }

        // Checking if 'i' greater than 'Y' and if 'i - Y' length rod can be cut into segments.
        if (i - y >= 0 && dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }

        // Checking if 'i' greater than 'Z' and if 'i - Z' length rod can be cut into segments.
        if (i - z >= 0 && dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    // If 'N' length rod cannot be cut into segments return 0 else return 'DP[N]'.
    if (dp[n] == -1)
    {
        return 0;
    }
    else
    {
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);

    int x1 = solve(n, x, y, z);

    if (x1 < 0)
    {
        return 0;
    }
    else
    {
        return x1;
    }
}
