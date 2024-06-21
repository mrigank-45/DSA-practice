#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < m; i++)
        {
            nums2[i] = nums2[i] * k;
        }

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n; i++)
        {
            mp1[nums1[i]]++;
        }

        for (int i = 0; i < m; i++)
        {
            mp2[nums2[i]]++;
        }

        vector<int> v1;
        vector<int> v2;

        for (auto x : mp1)
        {
            v1.push_back(x.first);
        }

        for (auto x : mp2)
        {
            v2.push_back(x.first);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int i = 0, j = 0;
        long long int cnt = 0;
        n = v1.size(), m = v2.size();

        while (j < m)
        {
            while (i < n && v1[i] < v2[j])
            {
                i++;
            }

            int temp = i;

            while (i < n)
            {
                if (v1[i] % v2[j] == 0)
                {
                    cnt = cnt + (long long)mp1[v1[i]] * (long long)mp2[v2[j]];
                }
                i++;
            }

            i = temp;
            j++;
        }

        return cnt;
    }
};
