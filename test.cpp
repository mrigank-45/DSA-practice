#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxLeft = nums[0];
        int maxRight = nums[0];

        int prod = 1;

        bool zeroPresent = false;

        for (auto i : nums)
        {
            if (i != 0 && prod > INT_MAX / i)
            {
                prod = prod;
                cout << "reached" << endl;
            }
            else if (i != 0 && prod < INT_MIN / i)
            {
                prod = prod;
                cout << "reached" << endl;
            }
            else
            {
                prod *= i;
            }
            if (i == 0)
            {
                prod = 1;
                zeroPresent = true;
                continue;
            }
            maxLeft = max(maxLeft, prod);
        }

        prod = 1;

        for (int j = nums.size() - 1; j >= 0; j--)
        {
            if (nums[j] != 0 && prod > INT_MAX / nums[j])
            {
                prod = prod;
                cout << "reached" << endl;
            }
            else if (nums[j] != 0 && prod < INT_MIN / nums[j])
            {
                prod = prod;
                cout << "reached" << endl;
            }
            else
            {
                prod *= nums[j];
            }
            if (nums[j] == 0)
            {
                prod = 1;
                zeroPresent = true;
                continue;
            }
            maxRight = max(maxRight, prod);
        }

        if (zeroPresent)
        {
            return max(max(maxLeft, maxRight), 0);
        }
        else
        {
            return max(maxLeft, maxRight);
        }
    }
};
