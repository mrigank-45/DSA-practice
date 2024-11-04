#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalOrGreater(int val, vector<int> arr)
    {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= val)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        if (ans == -1)
            return 0;

        return arr.size() - ans;
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (success % (long long)spells[i] == 0)
                ans.push_back(equalOrGreater(success / (long long)spells[i], potions));
            else
                ans.push_back(equalOrGreater(success / (long long)spells[i] + 1, potions));
        }
        return ans;
    }
};
