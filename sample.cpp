#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int element : nums)
        {
            if (element <= min1)
            {
                min1 = element;
            }
            else if (element <= min2)
            {
                min2 = element;
            }
            else
            {
                return true;
            }
            return false;
        }
    }
};
