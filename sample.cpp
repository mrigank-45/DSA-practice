#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int l = 0, r = n - 1;
        int sum = skill[l] + skill[r];
        while (l < r)
        {
            if (skill[l] + skill[r] != sum)
            {
                return -1;
            }
            else
            {
                ans += skill[l] * skill[r];
                l++;
                r--;
            }
        }

        return ans;
    }
};
