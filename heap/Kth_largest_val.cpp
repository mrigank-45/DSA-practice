// We have to fimd Kth largest element in an array. We can do this by simple approach as well, but this is a new approach which is used
//  in a lot of question involving heap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minh;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            minh.push(nums[i]);
            if (minh.size() > k)
                minh.pop();
        }
        return minh.top();

        //    sort(nums.begin(), nums.end());
        //    return nums[n-k];
    }
};
