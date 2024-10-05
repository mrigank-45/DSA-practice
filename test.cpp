#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        vector<string> ans;

        sort(access_times.begin(), access_times.end());

        int cnt = 1;
        int time = stoi(access_times[0][1]);
        string curr = access_times[0][0];
        for (int i = 1; i < n; i++)
        {
            if (access_times[i][0] == curr)
            {
                if (stoi(access_times[i][1]) - time < 100)
                {
                    cnt++;
                    if (cnt == 3)
                    {
                        ans.push_back(curr);
                    }
                }
                else
                {
                    cnt = 1;
                    time = stoi(access_times[i][1]);
                }
            }
            else
            {
                cnt = 1;
                time = stoi(access_times[i][1]);
                curr = access_times[i][0];
            }
        }

        return ans;
    }
};
