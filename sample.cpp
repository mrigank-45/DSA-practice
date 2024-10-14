#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        long long ans = 0;

        while(k--)
        {
            int ele = pq.top();
            ans += ele;
            pq.pop();
            pq.push(ceil((double)ele / 3));
        }
        return ans;

    }
};
