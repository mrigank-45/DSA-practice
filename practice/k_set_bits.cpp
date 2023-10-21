// Sum of Values at Indices With K Set Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {
        int count = 0;
        while (n)
        {
            if (n & 1)
            {
                count++;
            }

            n = n >> 1; 
        }
        return count;
    }

    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (countSetBits(i) == k)
            {
                sum += nums[i];
            }
            
        }
        return sum;
    }
};
