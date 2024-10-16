#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp; // {rem, freq}

        for (int i = 0; i < n; i++)
        {
            int rem = arr[i] % k;
            if (rem < 0)
                rem += k;
            mp[rem]++;
        }

        for (auto it : mp)
        {
            int rem = it.first;
            int freq = it.second;

            if (rem == 0 || 2 * rem == k)
            {
                if (freq % 2 != 0)
                    return false;
            }
            else
            {
                if (mp[k - rem] != freq)
                    return false;
            }
        }

        return true;
    }
};
