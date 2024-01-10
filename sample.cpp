#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxArrayValue(vector<int> &num)
    {
        vector<long long int> nums;
        for (int i = 0; i < num.size(); i++)
        {
            nums.push_back(num[i]);
        }
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] >= nums[i - 1])
            {
                nums[i - 1] = nums[i - 1] + nums[i];
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
