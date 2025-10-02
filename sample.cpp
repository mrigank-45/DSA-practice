#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(string s, string curr)
    {
        int  i = 0, j = 0;
        while(i < s.size() && j < curr.size())
        {
            if(s[i] == curr[j])
                j++;
            i++;
        }
        if(j == curr.size())
            return true;
        return false;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int cnt = 0;
        unordered_map<string, int> words_map;
        for(auto &word: words)
            words_map[word]++;

        for(auto &word: words_map)
            if(check(s, word.first))
                cnt+= word.second;
        return cnt;
    }
};
