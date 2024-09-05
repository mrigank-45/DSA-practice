#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = n - 1; i >= 0; i--)
        {
            mp[i] = pq;
            pq.push({nums[i], i});
        }

        vector<pair<int, int>> swaps;
        map<pair<int,int>, bool> vis;

        for (int i = 0; i < n; i++)
        {
            for (auto it : swaps)
            {
                if (it.second > i)
                {
                    mp[i].push(it);
                }
            }
            while (!mp[i].empty() && mp[i].top().first < nums[i])
            {
                if (abs(mp[i].top().first - nums[i]) <= limit && !vis[mp[i].top()])
                {
                    swaps.push_back({nums[i], mp[i].top().second});
                    vis[{mp[i].top().first,mp[i].top().second}] = true;
                    swap(nums[i], nums[mp[i].top().second]);
                    break;
                }
                else
                {
                    mp[i].pop();
                }
            }
        }

        return nums;
    }
};
