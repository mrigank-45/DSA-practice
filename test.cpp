#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool equal(string s1, string s2)
    {
        // 1 swap
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = i + 1; j < s1.size(); j++)
            {
                swap(s1[i], s1[j]);
                if (s1 == s2)
                {
                    return true;
                }
                swap(s1[i], s1[j]);
            }
        }

        for (int i = 0; i < s2.size(); i++)
        {
            for (int j = i + 1; j < s2.size(); j++)
            {
                swap(s2[i], s2[j]);
                if (s1 == s2)
                {
                    return true;
                }
                swap(s2[i], s2[j]);
            }
        }

        // 2 swap
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = i + 1; j < s1.size(); j++)
            {
                swap(s1[i], s1[j]);
                for (int k = 0; k < s1.size(); k++)
                {
                    for (int l = k + 1; l < s1.size(); l++)
                    {
                        swap(s1[k], s1[l]);
                        if (s1 == s2)
                        {
                            return true;
                        }
                        swap(s1[k], s1[l]);
                    }
                }
                swap(s1[i], s1[j]);
            }
        }

        for (int i = 0; i < s2.size(); i++)
        {
            for (int j = i + 1; j < s2.size(); j++)
            {
                swap(s2[i], s2[j]);
                for (int k = 0; k < s2.size(); k++)
                {
                    for (int l = k + 1; l < s2.size(); l++)
                    {
                        swap(s2[k], s2[l]);
                        if (s1 == s2)
                        {
                            return true;
                        }
                        swap(s2[k], s2[l]);
                    }
                }
                swap(s2[i], s2[j]);
            }
        }

        return false;
    }
    bool check(int x, int y)
    {
        int diff = 0;
        string s1 = "";
        string s2 = "";
        while (x != 0 || y != 0)
        {
            int v1 = x % 10;
            int v2 = y % 10;
            if (v1 != v2)
            {
                s1 = s1 + to_string(v1);
                s2 = s2 + to_string(v2);

                diff++;
            }
            x = x / 10;
            y = y / 10;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        if (diff == 0)
        {
            return true;
        }
        else if (diff == 1 || diff > 4)
        {
            return false;
        }
        else if (equal(s1, s2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(nums[i], nums[j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
