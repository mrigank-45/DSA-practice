// Input: [1,2,-3,0,-4,-5]
// Output: 20
// Approach: Idea is to find the maximum product from both sides,i.e, once in a forwarding direction and another in the
// backward direction and return the maximum of both.

#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &nums)
{
    int maxLeft = nums[0];
    int maxRight = nums[0];

    int prod = 1;

    bool zeroPresent = false; // to check if zero is ever present in array

    for (auto i : nums)
    {
        prod *= i;
        if (i == 0)
        {
            prod = 1;
            zeroPresent = true;
            continue;
        }
        maxLeft = max(maxLeft, prod);
    }

    prod = 1;

    for (int j = nums.size() - 1; j >= 0; j--)
    {
        prod *= nums[j];
        if (nums[j] == 0)
        {
            prod = 1;
            zeroPresent = true;
            continue;
        }
        maxRight = max(maxRight, prod);
    }

    if (zeroPresent)
    {
        return max(max(maxLeft, maxRight), 0);
    }
    return max(maxLeft, maxRight);
}

int main()
{
    vector<int> nums = {0, 5, -4, 1, 200, -6, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums);
    return 0;
}
