#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long helper(vector<int> nums, int k, int i)
    {
        if (nums[i] == k)
        {
            return 0;
        }
        long long ans = 0;
        if (nums[i] < k)
        {
            if (i != nums.size() - 1 && nums[i + 1] <= k)
            {
                ans += nums[i + 1] - nums[i];
                nums[i] = nums[i + 1];
                if (nums[i] == k)
                    return ans;
            }
            if (i == nums.size() - 1)
            {
                ans += k - nums[i];
                nums[i] = k;
                return ans;
            }

            long long temp = 0;
            int j = i;
            while (j < nums.size() && nums[j] < k)
            {
                temp += k - nums[j];
                nums[j] = k;
                j++;
            }
            ans += temp;
        }
        else
        {
            if (i != 0 && nums[i - 1] >= k)
            {
                ans += nums[i] - nums[i - 1];
                nums[i] = nums[i - 1];
                if (nums[i] == k)
                    return ans;
            }
            if (i == 0)
            {
                ans += nums[i] - k;
                nums[i] = k;
                return ans;
            }

            long long temp = 0;
            int j = i;
            while (j >= 0 && nums[j] > k)
            {
                temp += nums[j] - k;
                nums[j] = k;
                j--;
            }
            ans += temp;
        }

        return ans;
    }
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n % 2 == 1)
        {
            return helper(nums, k, n / 2);
        }
        else
        {
            return helper(nums, k, n / 2);
        }
    }
};
