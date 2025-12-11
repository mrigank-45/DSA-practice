#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getSum(long long n)
    {
        return (long long)n * (long long)(n + 1) / 2;
    }

    bool groupPossible(vector<long long> &ps, int numofGroup)
    {
        int n = ps.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (numofGroup == 0)
                return true;
            ;

            // At each index check if no.of unqiue people are greater than or equal to group no. and
            // total no. of people till that index are ≥ sum of n numbers.
            if ((i + 1 >= numofGroup) && getSum(numofGroup) <= ps[i])
            {
                numofGroup--;
            }
            else
                return false;
        }
        return true;
    }

    int maxIncreasingGroups(vector<int> &usageLimits)
    {

        int l = 0;
        int r = usageLimits.size(); // max
        //  Sort the usageLimits array in non-decreasing order
        sort(usageLimits.begin(), usageLimits.end());
        vector<long long> ps(r);
        for (int i = 0; i < r; i++)
        {
            if (i == 0)
                ps[i] = usageLimits[i];
            else
                ps[i] = ps[i - 1] + usageLimits[i];
        }

        int ans = 0;

        while (l <= r)
        {
            //  Use binary search to find the maximum number of groups
            int mid = l + (r - l) / 2;

            if (groupPossible(ps, mid)) //  Check if it's possible to create 'mid' groups of distinct numbers
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }
};
