#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct pair_hash
    {
        size_t operator()(const pair<int, int> &p) const
        {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> st;

        unordered_set < pair<int, int>, pair_hash> pairs;
        for (int i = 0; i < n; i++)
        {
            if (st.find(nums[i] - k) != st.end())
            {
                pairs.insert({nums[i] - k, nums[i]});
            }
            if (st.find(nums[i] + k) != st.end())
            {
                pairs.insert({nums[i], nums[i] + k});
            }
            st.insert(nums[i]);
        }
        return pairs.size();
    }
};
