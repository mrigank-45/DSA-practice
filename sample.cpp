#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int cnt1 = n / 2, cnt2 = n / 2;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n; i++)
        {
            mp1[nums1[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            mp2[nums2[i]]++;
        }

        // Step 1
        for (auto it : mp1)
        {
            if (cnt1 == 0)
            {
                break;
            }

            if (it.second > 1)
            {
                if (it.second - 1 > cnt1)
                {
                    mp1[it.first] -= cnt1;
                    cnt1 = 0;
                }
                else
                {
                    cnt1 -= it.second - 1;
                    mp1[it.first] = 1;
                }
            }
        }
        for (auto it : mp2)
        {
            if (cnt2 == 0)
            {
                break;
            }

            if (it.second > 1)
            {
                if (it.second - 1 > cnt2)
                {
                    mp2[it.first] -= cnt2;
                    cnt2 = 0;
                }
                else
                {
                    cnt2 -= it.second - 1;
                    mp2[it.first] = 1;
                }
            }
        }

        // step 2
        if (cnt1 > 0)
        {
            for (auto it : mp1)
            {
                if (cnt1 == 0)
                {
                    break;
                }
                if (mp2.find(it.first) != mp2.end() && mp2[it.first] > 0)
                {
                    mp1[it.first] = 0;
                    cnt1--;
                }
            }
        }
        if (cnt2 > 0)
        {
            for (auto it : mp2)
            {
                if (cnt2 == 0)
                {
                    break;
                }
                if (mp1.find(it.first) != mp1.end() && mp1[it.first] > 0)
                {
                    mp2[it.first] = 0;
                    cnt2--;
                }
            }
        }

        // step 3
        if (cnt1 > 0)
        {
            for (auto it : mp1)
            {
                if (cnt1 == 0)
                {
                    break;
                }
                if (it.second > 0)
                {
                    mp1[it.first] = 0;
                    cnt1--;
                }
            }
        }
        if (cnt2 > 0)
        {
            for (auto it : mp2)
            {
                if (cnt2 == 0)
                {
                    break;
                }
                if (it.second > 0)
                {
                    mp2[it.first] = 0;
                    cnt2--;
                }
            }
        }

        unordered_set<int> s;
        for (auto it : mp1)
        {
            if (it.second > 0)
            {
                s.insert(it.first);
            }
        }
        for (auto it : mp2)
        {
            if (it.second > 0)
            {
                s.insert(it.first);
            }
        }
        return s.size();
    }
};
