// Smallest Subsequence of Distinct Characters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int freq[26] = {0};
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        stack<char> st;
        bool inStack[26] = {false};

        for (char c : s)
        {
            freq[c - 'a']--;

            if (inStack[c - 'a'])
            {
                continue;
            }

            // Ensure the stack remains lexicographically smallest
            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0)
            {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string result;
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
