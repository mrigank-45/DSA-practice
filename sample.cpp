#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<pair<int, int>> dq;
        int n = nums.size();

        vector<int> ans;

        // first window
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back({nums[i], i});
        }
        ans.push_back(dq.front().first);

        for (int i = k; i < n; i++)
        {
            while (!dq.empty() && dq.front().second <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back({nums[i], i});

            ans.push_back(dq.front().first);
        }

        return ans;
    }
};
