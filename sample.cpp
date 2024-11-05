#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int ans = 0;
        int i = 0, j = n - 1;

        sort(nums.begin(), nums.end());

        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                ans++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return ans;
    }
};
