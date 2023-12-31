// Minimum Absolute Difference Between Elements With Constraint

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &arr, int x)
    {
        if (x == 0)
            return 0;
        int n = arr.size();
        map<int, int> mp;
        for (int i = x; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int mini = INT_MAX; // ans

        for (int i = 0; i < n - x; i++)
        {
            int elem = arr[i];
            auto it = mp.lower_bound(elem); // just greater than or equal to this element
            if (it != mp.end())  // if found, consider it
            {
                mini = min(mini, abs(it->first - elem));
            }
            if (it != mp.begin() and it != mp.end())  // if not the first element, consider previous element too
            {
                it--;
                mini = min(mini, abs(it->first - elem));
            }
            if (it == mp.end())  // if not found, update ans with max and min element
            {
                mini = min(mini, abs((--mp.end())->first - elem));
                mini = min(mini, abs(mp.begin()->first - elem));
            }

            // to maintain distance of x
            mp[arr[i + x]]--;
            if (mp[arr[i + x]] == 0)
                mp.erase(arr[i + x]);
        }

        return mini;
    }
};
