#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion
    int solve1(vector<int> &coins, int t)
    {
        // reached ans
        if (t == 0)
        {
            return 0;
        }
        if (t < 0)
        {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            // include the coin
            int ans = solve1(coins, t - coins[i]);
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        return mini;
    }

    // recursion + memoization
    int solve2(vector<int> &coins, int t, vector<int> &dp)
    {
        // base case
        if (t == 0)
        {
            return 0;
        }
        if (t < 0)
        {
            return INT_MAX;
        }

        if (dp[t] != -1)
        {
            return dp[t];
        }
        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve2(coins, t - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        
        return dp[t] = mini;
    }

    // tabulation
    int solve3(vector<int> &coins, int t)
    {
        vector<int> dp(t + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= t; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[t];
    }
    
    int coinChange(vector<int> &coins, int amount)
    {
        // for solution 1
        //  int k= solve1(coins,amount);
        //  if(k==INT_MAX){return -1;}
        //  return k;

        // for solution 2
        //  vector<int> dp(amount+1,-1);
        //  int k= solve2(coins,amount,dp);
        //  if(k==INT_MAX){return -1;}
        //  return k;

        // for solution 3
        int ans = solve3(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
