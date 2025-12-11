// Maximum Beauty of an Array After Applying Operation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n == 1)
        {
            return 1;
        }
        
        int ans = INT_MIN;

        // now find max range where all elements can be made equal

        for (int i = 0; i < n; i++)
        {
            int mini = nums[i];

            int low = i;
            int high = nums.size() - 1;

            int mid = low + (high - low) / 2;

            int temp = i;

            while (low <= high)
            {
                if (nums[mid] - mini > 2 * k)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                    temp = max(temp, mid);
                }

                mid = low + (high - low) / 2;
            }

            ans = max(ans, temp - i + 1);
        }

        return ans;
    }
};
