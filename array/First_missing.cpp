// First Missing Positive

// Approach: For each positive integer n in the array, calculate the index idx = abs(n) - 1
// If this index is within the array’s bounds and the number at that position is positive, mark it by making
// it negative. This marking process serves as an indicator that the integer n is present in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        nums.erase(remove_if(nums.begin(), nums.end(), [](int n)
                             { return n <= 0; }),
                   nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int n = abs(nums[i]);
            if (n <= nums.size() && nums[n - 1] > 0)
            {
                nums[n - 1] = -nums[n - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
