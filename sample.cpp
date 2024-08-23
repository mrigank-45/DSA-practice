#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        while (!pq.empty())
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }
};
