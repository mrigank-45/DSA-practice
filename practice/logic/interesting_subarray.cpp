// Explanation: https://leetcode.com/problems/count-of-interesting-subarrays/solutions/3995980/video-explanation-intuitive-solution/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();

        int prefix_sum = 0;
        long long int result = 0;

        map<int, int> frq;
        frq[k % modulo] = 1;

        for (int j = 0; j < n; j++)
        {
            int cur = (nums[j] % modulo) == k;
            prefix_sum = (prefix_sum + cur) % modulo;

            result += frq[prefix_sum];
            frq[(prefix_sum + k) % modulo]++;
        }

        return result;
    }
};
