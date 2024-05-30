#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 1;

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                continue;
            }
            else
            {
                if (ans == 0 && nums[i] != 1)
                {
                    break;
                }
                else if (ans == 0 && nums[i] == 1)
                {
                    ans++;
                    continue;
                }
                else
                {
                    if (i > 0 && nums[i] == nums[i - 1] + 1)
                    {
                        ans++;
                    }
                    else if (i > 0 && nums[i] == nums[i - 1])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return ans + 1;
    }
};
