#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int l1 = a.size();
        int l2 = b.size();
        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i <= s.size() - l1; i++)
        {
            if (s.substr(i, l1) == a)
            {
                v1.push_back(i);
            }
        }
        for (int i = 0; i <= s.size() - l2; i++)
        {
            if (s.substr(i, l2) == b)
            {
                v2.push_back(i);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> ans;

        for (int i = 0; i < v1.size(); i++)
        {
            auto justBig = lower_bound(v2.begin(), v2.end(), v1[i]);
            if (justBig != v2.end())
            {
                int index = *justBig;
                cout<<index<<endl;
                if (abs(index - v1[i]) <= k)
                {
                    ans.push_back(v1[i]);
                    continue;
                }
            }
            if (justBig != v2.begin())
            {
                justBig--;
                int index = *justBig;
                cout<<index<<endl;
                if (abs(index - v1[i]) <= k)
                {
                    ans.push_back(v1[i]);
                    continue;
                }
            }
            auto justSmall = upper_bound(v2.begin(), v2.end(), v1[i]);
            if (justSmall != v2.end())
            {
                int index = *justSmall;
                if (abs(index - v1[i]) <= k)
                {
                    ans.push_back(v1[i]);
                    continue;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
