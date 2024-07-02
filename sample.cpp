#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = nums[0];
        for (int i = 1; i < n; i++)
        {
            res = res ^ nums[i];
        }
        int cnt = 0;
        for (int i = 0; i <= 31; i++)
        {
            int a = res;
            int b = k;
            a = a >> i;
            b = b >> i;

            if ((a & 1) != (b & 1))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
