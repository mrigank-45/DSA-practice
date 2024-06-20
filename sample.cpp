#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> output;

        for (int i = 0; i <= n - 3; i++)
        {
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
                    output.push_back(sum);
                    low++;
                }
                else
                {
                    output.push_back(sum);
                    high--;
                }
            }
        }

        int ans = output[0];

        for (int i = 1; i < output.size(); i++)
        {
            if (abs(output[i] - target) < abs(ans - target))
            {
                ans = output[i];
            }
        }

        return ans;
    }
};
