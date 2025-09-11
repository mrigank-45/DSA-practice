#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        string prev = folder[0];
        vector<string> ans;
        ans.push_back(prev);
        for (int i = 1; i < n; i++)
        {
            string curr = folder[i];
            int k = prev.size();
            if (curr.size() <= k || curr.substr(0, k + 1) != prev + '/')
            {
                ans.push_back(curr);
                prev = curr;
            }
        }
        return ans;
    }
};
