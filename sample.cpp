#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int k, int n, int i, vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int max_val = 0;
        int max_ans = 0;

        for (int j = i; j < min(n, i + k); j++) {
            int len = j - i + 1;
            max_val = max(max_val, arr[j]);
            int sum = (len * max_val) + solve(arr, k, n, j + 1, dp);
            max_ans = max(max_ans, sum);
        }
        return dp[i] = max_ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, n, 0, dp);
    }
};
