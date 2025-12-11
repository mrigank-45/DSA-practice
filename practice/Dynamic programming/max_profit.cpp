#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<vector<int>> &offers, int i, vector<int> &dp)
    {
        if (i == offers.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int nottake = helper(offers, i + 1, dp);

        int next = offers.size();
        int low = i + 1;
        int high = offers.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (offers[mid][0] > offers[i][1])
            {
                high = mid - 1;
                next = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        int take = offers[i][2] + helper(offers, next, dp);
        return dp[i] = max(take, nottake);
    }

    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        sort(offers.begin(), offers.end());
        int m = offers.size();
        vector<int> dp(m, -1);
        return helper(offers, 0, dp);
    }
};
