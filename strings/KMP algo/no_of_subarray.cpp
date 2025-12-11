// Number of Subarrays That Match a Pattern II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> computeLPSArray(string pattern)
    {
        vector<int> lps(pattern.length(), 0);
        int len = 0;
        int i = 1;
        while (i < pattern.length())
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int KMPSearch(string text, string pattern)
    {
    }

    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        string word = "";
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                word += "B";
            }
            else if (nums[i - 1] > nums[i])
            {
                word += "A";
            }
            else
            {
                word += "C";
            }
        }

        string pat = "";
        for (int i : pattern)
        {
            if (i == 0)
                pat += "B";
            else if (i == -1)
                pat += "A";
            else if (i == 1)
                pat += "C";
        }

        string temp = pat + "#" + word;
        int n = temp.length();
        int m = pat.length();
        int cnt = 0;
        vector<int> lps = computeLPSArray(temp);

        for (int i = m; i < n; i++)
        {
            if (lps[i] == m)
                cnt++;
        }
        return cnt;
    }
};
