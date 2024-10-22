#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<int> &arr, int curr, vector<bool> &visited, vector<int> &dp)
    {
        if (curr < 0 || curr >= arr.size())
            return 0;

        if (visited[curr])
            return 0;

        if (arr[curr] == 0)
            return 1;

        if (dp[curr] != -1)
            return dp[curr];

        visited[curr] = true;

        int left = dfs(arr, curr - arr[curr], visited, dp);
        int right = dfs(arr, curr + arr[curr], visited, dp);

        visited[curr] = false;

        return dp[curr] = left || right;
    }
    bool canReach(vector<int> &arr, int curr)
    {
        int n = arr.size();

        vector<bool> visited(n, false);
        vector<int> dp(n, -1);

        return dfs(arr,curr,visited,dp);
    }
};
