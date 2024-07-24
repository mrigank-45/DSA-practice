#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int type = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 1)
                continue;
            if (nums[i] == 1)
            {
                if (type < 0)
                    type = 0;
            }
            if ((nums[i] == 1) && ((i - 1 >= 0 && nums[i - 1] == 1) || (i + 1 < n && nums[i + 1] == 1)))
            {
                if (type < 1)
                    type = 1;
            }
            if ((nums[i] == 1) && (i - 1 >= 0 && nums[i - 1] == 1) && (i + 1 < n && nums[i + 1] == 1))
            {
                if (type < 2)
                    type = 2;
                break;
            }
        }
        long long moves = 0;

        if (type == 0)
        {
            k--;
        }
        else if (type == 1)
        {
            k = k - 2;

            moves++;
        }
        else if (type == 2)
        {
            k = k - 3;
            moves = moves + 2;
        }

        if (k > maxChanges)
        {
            return -1;
        }
        else
        {
            moves = moves + (k * 2);
        }

        return moves;
    }
};
