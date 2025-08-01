#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        unordered_map<int,int> mp;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = cnt;
            while(i < n - 1 && abs(nums[i] - nums[i+1]) <= maxDiff)
            {
                mp[nums[i+1]] = cnt;
                i++;
            }
            cnt++;
        }
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            if (mp[nums[u]] == mp[nums[v]])
            {
                ans[i] = true;
            }
        }
        
        return ans;
    }
};
