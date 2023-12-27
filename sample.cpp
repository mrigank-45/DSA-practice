#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &offers, int i, vector<int> &DP)
    {
        // base case
        if (i == offers.size())
        {
            return 0;
        }

        // check if result for current state is already memoized
        if (DP[i] != -1)
        {
            return DP[i];
        }

        // include
        int prev = offers[i][1];
        int j = i + 1;
        while (j < offers.size() && offers[j][0] <= prev)
        {
            j++;
        }
        int includeProfit = solve(offers, j, DP) + offers[i][2];

        // exclude
        int excludeProfit = solve(offers, i + 1, DP);

        // calculate the maximum profit for the current state
        int maxProfit = max(includeProfit, excludeProfit);

        // memoize the result
        DP[i] = maxProfit;

        return maxProfit;
    }

    int tabulation(vector<vector<int>> &offers)
    {
        vector<int> DP(offers.size() + 1, -1);

        for (int i = offers.size() - 1; i >= 0; i--)
        {
            // exclude
            int excludeProfit = DP[i + 1];

            // include
            int prev = offers[i][1];
            int j = i + 1;
            while (j < offers.size() && offers[j][0] <= prev)
            {
                j++;
            }
            int includeProfit = -1;
            if (j == i + 1)
            {
             includeProfit = DP[j] + offers[i][2];
            }
            else {
                includeProfit = DP[j];
            }
            
            
            // calculate the maximum profit for the current state
            int maxProfit = max(includeProfit, excludeProfit);

            // memoize the result
            DP[i] = maxProfit;
        }

        return DP[0];
    }

    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        sort(offers.begin(), offers.end());

        vector<int> DP(offers.size() + 1, -1);

        int result = solve(offers, 0, DP);

        return result;
    }
};
