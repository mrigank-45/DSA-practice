#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToEqualizeArray(vector<int> &nums, int cost1, int cost2)
    {
        int n = nums.size();
        int mod = 1e9 + 7;

        int one = cost1, two;
        if (2 * cost1 < cost2)
        {
            two = 2 * cost1;
        }
        else
        {
            two = cost2;
        }

        int max = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == max && flag == 0)
            {
                flag = 1;
            }
            else
            {
                pq.push(nums[i]);
            }
        }
        int ans = 0;

        while (!pq.empty())
        {
            if (pq.size() == 1)
            {
                int x = pq.top();
                pq.pop();
                ans += (max - x) * one;
            }
            else
            {
                int x = pq.top();
                pq.pop();
                x++;
                int y = pq.top();
                pq.pop();
                y++;
                ans += two;

                if (x < max)
                {
                    pq.push(x);
                }
                if (y < max)
                {
                    pq.push(y);
                }
            }
        }

        return ans;
    }
};
