#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrays(vector<int> &nums)
    {
        int a_ = nums[0]; // Initialize a_ with the first element of nums.

        // Calculate bitwise AND of all elements in nums.
        for (int num : nums)
        {
            a_ &= num;
        }

        if (a_)
        {
            return 1; // If a_ is not zero, return 1.
        }

        int size = 1;       // Initialize the size to 1.
        a_ = (1 << 20) - 1; // Initialize a_ as a 20-bit mask of all 1s.

        for (int num : nums)
        {
            a_ &= num; // Calculate bitwise AND of a_ and the current element.

            if (a_ == 0)
            {
                size++;             // If a_ becomes zero, increment the size.
                a_ = (1 << 20) - 1; // Reset a_ to the 20-bit mask of all 1s.
            }
        }

        if (a_)
        {
            size--; // If a_ is not zero at the end, decrement the size.
        }

        return size; // Return the final size.
    }
};
