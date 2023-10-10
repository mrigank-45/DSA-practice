// We have to fimd Kth largest element in an array. We can do this by simple approach as well, but this is a new approach which is used
//  in a lot of question involving heap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = nums.size();
        // step: 1
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        // step: 2
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // step: 3
        return pq.top();

        //    sort(nums.begin(), nums.end());
        //    return nums[n-k];
    }
};
