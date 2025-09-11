#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, parity = 1;
        for (int i = 1; i < n; i++)
        {
            if (parity % 2 == 1 && nums[i] == nums[i - 1])
            {
                ans++;
            }
            else
            {
                parity++;
            }
        }
        if(parity % 2 == 1)
            ans++;  
        return ans;
    }
};
