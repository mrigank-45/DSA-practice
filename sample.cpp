#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, map<int, bool> &mp,  map<string,int> &dp, string temp)
    {
        bool flag = false;
        int ans = 0;

        if(dp.count(temp))
        {
            return dp[temp];
        }

        for (int i = 0; i < n; i++)
        {
            if (!mp[i])
            {
                int coins = nums[i];
                int j = i - 1;
                while (mp[j] && j >= 0)
                {
                    j--;
                }
                if (j != -1)
                {
                    coins *= nums[j];
                }
                j = i + 1;
                while (mp[j] && j < n)
                {
                    j++;
                }
                if (j != n)
                {
                    coins *= nums[j];
                }
                mp[i] = true;
                ans = max(ans, coins + solve(nums, n, mp, dp, temp + to_string(i)));
                mp[i] = false;
                flag = true;
            }
        }
        if (flag)
        {
            return dp[temp] = ans;
        }
        else
        {
            return dp[temp] = 0;
        }
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        map<int, bool> mp;
        map<string,int> dp;

        return solve(nums, n, mp, dp, "");
    }
};
