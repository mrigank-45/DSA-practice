#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(map<int, int> mp, int minFreq)
    {
        int maxFreq = minFreq + 1;
        for (auto it : mp)
        {
            if (it.second % maxFreq != 0 && (it.second / maxFreq + it.second % maxFreq) < minFreq)
            {
                return false;
            }
        }
        return true;
    }

    int minGroupsForValidAssignment(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        int minFreq = INT_MAX;
        for (auto it : mp)
        {
            minFreq = min(minFreq, it.second);
        }

        while (minFreq > 1)
        {
            if (isPossible(mp, minFreq))
            {
                break;
            }
            else
            {
                minFreq--;
            }
        }

        int maxFreq = minFreq + 1;
        int ans = 0;

        for (auto it : mp)
        {
            while (1)
            {
                if (it.second % maxFreq == 0)
                {
                    ans += it.second / maxFreq;
                    break;
                }
                else
                {
                    it.second -= minFreq;
                    ans++;
                }
            }
        }

        return ans;
    }
};
