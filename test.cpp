#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int x, int y)
    {
        int diff = 0;
        int c1, c2, c3, c4;
        while (x != 0 || y != 0)
        {
            int v1 = x % 10;
            int v2 = y % 10;
            if (v1 != v2)
            {
                if (diff == 0)
                {
                    c1 = v1;
                    c3 = v2;
                }
                else if (diff == 1)
                {
                    c2 = v1;
                    c4 = v2;
                }
                else
                {
                    return false;
                }
                diff++;
            }
            x = x / 10;
            y = y / 10;
        }

        if (diff == 0)
        {
            return true;
        }
        else if (diff == 1)
        {
            return false;
        }
        else if (c2 == c3 && c1 == c4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(nums[i], nums[j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
