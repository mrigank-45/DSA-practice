#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size();
        int even_cnt = 0, odd_cnt = 0, first_even = -1, first_odd = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                if (first_even == -1)
                {
                    first_even = i;
                }
                even_cnt++;
            }
            else
            {
                if (first_odd == -1)
                {
                    first_odd = i;
                }
                odd_cnt++;
            }
        }

        // odd_first subsequence
        int odd_length = 1;
        int parity = 0;
        for (int i = first_odd + 1; i < n; i++)
        {
            if (nums[i] % 2 == parity)
            {
                odd_length++;
                parity = 1 - parity;
            }
        }

        // even_first subsequence
        int even_length = 1;
        parity = 1;
        for (int i = first_even + 1; i < n; i++)
        {
            if (nums[i] % 2 == parity)
            {
                even_length++;
                parity = 1 - parity;
            }
        }

        return max(max(even_cnt, odd_cnt), max(even_length, odd_length));
    }
};
