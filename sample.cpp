#include <bits/stdc++.h>
using namespace std;
// Happy Students
// maximum-number-of-alloys

class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        // {val,{greater,smaller}}}
        map<int, pair<int, int>> m;
        int n = nums.size();

        for (long long int i = 0; i <= n; i++)
        {
            m[i].first = 0;
            m[i].second = 0;
        }

        for (long long int i = 0; i < n; i++)
        {
            long long int k = 0;
            while (k < nums[i])
            {
                m[k].first++;
                k++;
            }
            k = nums[i] + 1;
            while (k <= n)
            {
                m[k].second++;
                k++;
            }
        }

        long long int count = 0;
        for (long long int i = 0; i <= n; i++)
        {
            if (m[i].second == i && m[i].first == n - i)
            {
                count++;
            }
        }
        return count;
    }
};
