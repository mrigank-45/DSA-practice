#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, pair<int, int>> mp;
    int solve(vector<string> strs, int s, int i, int m, int n, int M, int N, vector<vector<vector<int>>> &dp)
    {
        if (i == s)
            return 0;
        
        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int ans = 0;
        // not choose
        ans = max(ans, solve(strs, s, i + 1, m, n, M, N, dp));

        // choose
        if (mp[i].first + m <= M && mp[i].second + n <= N)
        {
            ans = max(ans, 1 + solve(strs, s, i + 1, m + mp[i].first, n + mp[i].second, M, N, dp));
        }

        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int s = strs.size();
        for (int i = 0; i < s; i++)
        {
            string str = strs[i];
            int m = 0, n = 0;
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '0')
                {
                    m++;
                }
                else
                {
                    n++;
                }
            }
            mp[i] = {m, n};
        }
        vector<vector<vector<int>>> dp(s + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, s, 0, 0, 0, m, n, dp);
    }
};
