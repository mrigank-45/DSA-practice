#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        unordered_set<string> ans;
        vector<string> res;

        sort(access_times.begin(), access_times.end());

        int time = stoi(access_times[0][1]);
        string curr = access_times[0][0];
        for (int i = 0; i < n; i++)
        {
            curr = access_times[i][0];
            time = stoi(access_times[i][1]);
            i += 2;
            if (i >= n)
            {
                break;
            }
            if (access_times[i][0] == curr && stoi(access_times[i][1]) - time < 100)
            {
                ans.insert(curr);
            }
            else
            {
                i -= 2;
            }
        }

        for(auto &x: ans)
        {
            res.push_back(x);
        }
        return res;
    }
};
