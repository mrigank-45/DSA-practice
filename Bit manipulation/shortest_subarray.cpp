// Shortest Subarray With OR at Least K II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> setBitCount(32, 0); // To store count of set bits at each position

        int bitwiseOR = 0; // To store the bitwise OR of elements in the current window
        int left = 0;      // Left pointer of the sliding window
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            bitwiseOR |= nums[i];

            // Update the setBitCount after including nums[i] in the window
            for (int bit = 0; bit < 32; bit++)
            {
                if (nums[i] & (1 << bit))
                {
                    setBitCount[bit]++;
                }
            }

            // When condition is met, shrink the window
            while (left <= i && bitwiseOR >= k)
            {
                ans = min(ans, i - left + 1);

                // Remove nums[left] from the window and update setBitCount accordingly
                int updatedBitwiseOR = 0;
                for (int bit = 0; bit < 32; bit++)
                {
                    if (nums[left] & (1 << bit))
                    {
                        setBitCount[bit]--;
                    }
                    // If setBitCount is still greater than 0, set the bit in updatedBitwiseOR
                    if (setBitCount[bit])
                    {
                        updatedBitwiseOR |= (1 << bit);
                    }
                }
                bitwiseOR = updatedBitwiseOR;
                left++; 
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
