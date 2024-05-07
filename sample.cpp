// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?page=2&company=Morgan%20Stanley&sortBy=submissions
// can choose a index value many no. of times type Q

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int m, int v, vector<vector<int>> &dp)
    {
        if (m < 0)
        {
            return 1e9;
        }
        if (v == 0)
        {
            return dp[m][v] = 0;
        }
        if (dp[m][v] != -1)
        {
            return dp[m][v];
        }

        int take = 1e9;
        if (coins[m] <= v)
        {
            take = 1 + solve(coins, m, v - coins[m], dp);
        }

        int nottake = solve(coins, m - 1, v, dp);

        return dp[m][v] = min(take, nottake);
    }

    int minCoins(vector<int> &coins, int M, int V)
    {
        vector<vector<int>> dp(M, vector<int>(V + 1, -1));
        int ans = solve(coins, M - 1, V, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
