#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        int n = nums.size();

        while (k > 0)
        {
            // find minimum
            int val = nums[0];
            int index = 0;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] < val)
                {
                    val = nums[i];
                    index = i;
                }
            }
            nums[index] = val*multiplier;
            k--;
        }
        return nums;
    }
};
