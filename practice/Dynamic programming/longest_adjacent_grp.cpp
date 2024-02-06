// Longest Unequal Adjacent Groups Subsequence II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    // function to check the conditions of hamming distance and groups
    bool isok(int index, int i, vector<string> &words, vector<int> &groups)
    {

        if (groups[index] == groups[i])
        {
            return false;
        }

        if (words[index].size() != words[i].size())
        {
            return false;
        }

        int ham = 0;
        for (int k = 0; k < words[index].size(); k++)
        {
            if (words[index][k] != words[i][k])
            {
                ham++;
            }
            if (ham > 1)
            { // If the Hamming distance exceeds 1, it's not a valid match.
                return false;
            }
        }

        return (ham == 1); // Hamming distance must be exactly 1.
    }

    int solve(int index, int n, vector<string> &words, vector<int> &groups, vector<int> &next)
    {

        // if index reaches end
        if (index >= n)
        {

            return 0;
        }

        // using memoizatiosn
        if (dp[index] != -1)
        {

            return dp[index];
        }

        int ans = 1;
        for (int k = index + 1; k < n; k++)
        {

            if (isok(index, k, words, groups))
            {

                // check the answer
                int tempans = 1 + solve(k, n, words, groups, next);
                if (tempans > ans)
                {

                    // if answer is greater than previous then set next as k
                    // from current index next = k
                    ans = tempans;
                    next[index] = k;
                }
            }
        }

        return dp[index] = ans;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {

        dp.resize(n, -1);

        int maxi = 0, index = 0;

        // keeping next stored of each indx to rebuild the sequence
        vector<int> next(n, -1);
        for (int i = 0; i < n; i++)
        {

            int ans = solve(i, n, words, groups, next);
            if (maxi < ans)
            {

                maxi = ans;
                index = i;
            }
        }

        vector<string> s;

        // while next != -1 , means no possible next
        while (index != -1)
        {

            // push word at index
            s.push_back(words[index]);
            // move to next index
            index = next[index];
        }

        return s;
    }
};
