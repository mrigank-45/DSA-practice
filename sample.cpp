#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        long long n = nums.size();
        int ans = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        while (!pq.empty())
        {
            if (pq.top() >= k)
            {
                break;
            }
            if (pq.size() == 1)
            {
                ans = -1;
                break;
            }
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long temp = min(a, b) * 2 + max(a, b);
            pq.push(temp);
            ans++;
        }
        return ans;
    }
};
