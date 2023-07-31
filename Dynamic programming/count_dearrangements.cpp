#include <bits/stdc++.h>
using namespace std;

// recursion + memorization
long long int countDerangements(int n, vector<long long int> dp)
{
    // Base conditions.
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Recurse for other subproblems.
    dp[n] = ((n - 1) * (countDerangements(n - 1, dp) + countDerangements(n - 2, dp)));

    return dp[n];
}

// tabulation
long long int countDerangements(int n)
{
    long long int dp[n + 1] = {0};

    // Base cases.
    dp[1] = 0;
    dp[2] = 1;

    // Fill dp[0..'N'] in bottom up manner using above recursive formula.
    for (int i = 3; i <= n; ++i)
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2]));

    // Return result for 'N'.
    return dp[n];
}

// space optamization
long long int countDerangements(int n)
{
    // Base case.
    if (n == 1 or n == 2)
    {
        return n - 1;
    }

    // Variable for storing previous values.
    long long int prevOne = 0;
    long long int prevTwo = 1;

    for (int i = 3; i <= n; ++i)
    {
        long long int cur = ((i - 1) * (prevOne + prevTwo));
        prevOne = prevTwo;
        prevTwo = cur;
    }

    // Return result for 'N'.
    return prevTwo;
}
