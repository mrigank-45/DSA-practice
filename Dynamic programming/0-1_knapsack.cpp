#include <bits/stdc++.h>
using namespace std;

// recursion + memorization
int solve1(vector<int> &wt, vector<int> &val, int index, int W, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[index][W] != -1)
    {
        return dp[index][W];
    }

    int exclude = 0 + solve1(wt, val, index - 1, W, dp);

    int include = INT_MIN;
    if (wt[index] <= W)
    {
        include = val[index] + solve1(wt, val, index - 1, W - wt[index], dp);
    }

    dp[index][W] = max(exclude, include);
    return dp[index][W];
}

// tabulation
int solve2(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // analyze base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= w)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    // for rest of cases (2 loop becs it is 2D DP)
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = INT_MIN;

            int exclude = 0 + dp[index - 1][wt];

            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }

            dp[index][wt] = max(exclude, include);
        }
    }

    return dp[n - 1][capacity];
}

// space optamization 1 (2 vectors, prev and curr)
int solve3(vector<int> weight, vector<int> value, int n, int capacity)
{
    // we just need current and previous index row weight array
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // analyze base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= w)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    // for rest of cases (2 loop becs it is 2D DP)
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = INT_MIN;

            int exclude = 0 + prev[wt];

            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }

            curr[wt] = max(exclude, include);
        }
        prev = curr;
    }

    return prev[capacity];
}

// not very clear
// space optamization 2 (just prev vector and itrerate weight from right to left)
int solve3(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);

    // analyze base case
    for (int i = weight[0]; i <= capacity; i++)
    {
        prev[i] = value[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int notTaken = 0 + prev[wt];

            int taken = INT_MIN;
            if (weight[index] <= wt)
                taken = value[index] + prev[wt - weight[index]];

            prev[wt] = max(notTaken, taken);
        }
    }

    return prev[capacity];
}

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    // 2D dp since 2 states are changing (index and capacity)
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve1(wt, val, n - 1, W, dp);
}
