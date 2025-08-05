#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v = nums;
        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1;
        while (i < n)
        {
            if (nums[i] == v[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        while (j >= 0)
        {
            if (nums[j] == v[j])
            {
                j--;
            }
            else
            {
                break;
            }
        }

        if (i == n || j == -1 || i >= j)
        {
            return 0;
        }
        else
        {
            return j - i + 1;
        }
    }
};
