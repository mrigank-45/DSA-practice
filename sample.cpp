#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        map<int, int> m;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        int maxi = INT_MIN;

        for (auto it : m)
        {
            cout << it.first << " " << it.second << endl;
            maxi = max(maxi, it.second);
        }

        if ((n - maxi) > k)
        {
            return 0;
        }
        else
        {
            return maxi;
        }
    }
};
