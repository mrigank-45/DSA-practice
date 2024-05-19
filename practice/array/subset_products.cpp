// Number of subsets with product less than k

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subset(int i, int n, int k, int prod, int arr[], vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (prod <= k)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (dp[i][prod] != -1)
        {
            return dp[i][prod];
        }
        else
        {
            int take = 0, nottake = subset(i + 1, n, k, prod, arr, dp);
            if (arr[i] * prod <= k)
            {
                take = subset(i + 1, n, k, prod * arr[i], arr, dp);
            }

            return dp[i][prod] = take + nottake;
        }
    }
    int numOfSubsets(int arr[], int N, int K)
    {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
        
        return subset(0, N, K, 1, arr, dp) - 1;
    }
};
