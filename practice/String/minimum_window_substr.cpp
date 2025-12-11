// Minimum Window Substring | Leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            return "";
        }

        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        for (char c : t)
        {
            map[c]++;
        }

        while (end < s.length())
        {
            // here, map value of char present in just s will be -ve or 0, only those in t will be +ve
            // when count becomes 0, it means all char in t will have map value 0
            if (map[s[end++]]-- > 0)
            {
                count--;
            }

            while (count == 0)
            {
                if (end - start < minLen)
                {
                    startIndex = start;
                    minLen = end - start;
                }
                
                // here char present only in s will never have map value greater than 0 since we hace already decremented it
                if (map[s[start++]]++ == 0)
                {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
