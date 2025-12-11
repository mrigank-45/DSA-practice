// Split Array into Consecutive Subsequences

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> left, seq;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            ++left[nums[i]];
        for (int i = 0; i < n; ++i)
        {
            int x = nums[i];
            if (!left[x])
                continue;
            if (seq[x - 1])
            {
                --left[x];
                --seq[x - 1];
                ++seq[x];
            }
            else
            {
                if (!left[x + 2] || !left[x + 1])
                    return false;
                --left[x];
                --left[x + 1];
                --left[x + 2];
                ++seq[x + 2];
            }
        }
        return true;
    }
};
