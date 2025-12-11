// Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/3066058/c-easy-solution-with-explaination-in-o-n-time-complexity
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int total_sum = 0, curr_sum1 = 0, curr_sum2 = 0, mxsum_subary = INT_MIN, minsum_subary = INT_MAX;
        for (auto i : A)
        {
            total_sum += i;
            curr_sum1 += i;
            curr_sum2 += i;
            mxsum_subary = max(mxsum_subary, curr_sum1);
            if (curr_sum1 < 0)
                curr_sum1 = 0;
            minsum_subary = min(curr_sum2, minsum_subary);
            if (curr_sum2 > 0)
                curr_sum2 = 0;
        }
        return (total_sum == minsum_subary) ? mxsum_subary : max(mxsum_subary, total_sum - minsum_subary);
    }
};
