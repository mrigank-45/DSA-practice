#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int dp[77][2000][2000];
    long long int solve(long long int n, long long int curr, long long int temp)
    {
        if (n == 0LL)
        {
            return curr;
        }

        if (dp[n][curr][temp] != -1LL)
        {
            return dp[n][curr][temp];
        }

        long long int c1 = 0LL, c2 = 0LL, c3 = 0LL;

        // key 1
        c1 = solve(n - 1LL, curr + 1LL, temp);

        // key 2 and 3
        if (n >= 2LL)
        {
            c2 = solve(n - 2LL, curr, curr);
        }

        // key 4
        c3 = solve(n - 1LL, curr + temp, temp);

        dp[n][curr][temp] = max(c1, max(c2, c3));

        return dp[n][curr][temp];
    }

    long long int optimalKeys(int n)
    {
        memset(dp, -1LL, sizeof(dp));
        long long int n1 = (long long int)n;
        return solve(n1, 0LL, 0LL);
    }
};
