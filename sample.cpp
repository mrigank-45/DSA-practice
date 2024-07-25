#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        int n = nums.size();

        map<long long, long long> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = 0;
        }

        priority_queue<pair<long long, long long>> pq;

        for (auto it : mp)
        {
            pq.push({0, it.first});
        }

        vector<long long> ans;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});

            while (pq.top().first != mp[pq.top().second])
            {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
