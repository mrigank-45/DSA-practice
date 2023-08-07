// Maximum Height by Stacking Cuboids (leetcode)
// Q based on LIS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &base1, vector<int> &base2)
    {
        if (base2[0] <= base1[0] && base2[1] <= base1[1] && base2[2] <= base1[2])
        {
            return true;
        }
        else
            return false;
    }

    int solve(vector<vector<int>> &nums, int n)
    {
        vector<int> currrow(n + 1, 0);
        vector<int> nextrow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // INCLUDE THE HEIGHT
                int take = 0;
                if (prev == -1 || check(nums[curr], nums[prev])) //
                    take = nums[curr][2] + nextrow[curr + 1];

                // EXCLUDE THE HEIGHT
                int notake = 0 + nextrow[prev + 1];

                currrow[prev + 1] = max(take, notake);
            }
            // after ervy iteration upper row will be equal to currrow
            nextrow = currrow;
        }
        return nextrow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &i : cuboids)
        {
            sort(i.begin(), i.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids, cuboids.size());
    }
};
