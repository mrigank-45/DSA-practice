#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n, int i, bool flag, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }

    if (dp[i][flag] != -1)
    {
        return dp[i][flag];
    }

    if (flag)
    {
        return dp[i][flag] = max(arr[i] + solve(arr, n, i + 1, !flag, dp), solve(arr, n, i + 1, flag, dp));
    }
    else
    {
        return dp[i][flag] = solve(arr, n, i + 1, !flag, dp);
    }
}

int tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = max(arr[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = dp[i + 1][1];
    }

    return dp[0][1];
}

int tabulationSpace(vector<int> &arr)
{
    int n = arr.size();

    pair<int,int> curr, next;
    next.first = 0;
    next.second = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        curr.second = max(arr[i] + next.first, next.second);
        curr.first = next.second;
        
        next = curr;
    }

    return curr.second;
}

int maxLoot(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return solve(arr, n, 0, 1, dp);
}

int main()
{
    vector<int> arr = {6, 7, 1, 3, 8, 2, 4};
    cout << tabulationSpace(arr);
    return 0;
}
