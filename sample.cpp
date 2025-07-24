#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        int n = nums.size();
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i < k; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                q.push(i);
            }
        }
        if (q.empty())
            ans.push_back(nums[k - 1]);
        else
            ans.push_back(-1);

        int l = 1, r = k;

        while (r < n)
        {
            if (nums[r] != nums[r - 1] + 1)
                q.push(r);

            while (!q.empty() && q.front() <= l)
            {
                q.pop();
            }
            if (q.empty())
            {
                ans.push_back(nums[r]);
            }
            else
            {
                ans.push_back(-1);
            }
            l++;
            r++;
        }
        return ans;
    }
};
