#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        int n = clips.size();
        sort(clips.begin(), clips.end());

        if (clips[0][0] != 0)
            return -1;

        int last = clips[0][1], cnt = 1, prev = 0;

        for (int i = 0; i < n; i++)
        {
            if (clips[i][0] > last)
                return -1;

            if (clips[i][1] > last)
            {
                if (clips[i][0] > prev)
                {
                    cnt++;
                    prev = max(prev, last);
                }
                last = clips[i][1];
            }
            if (last >= time)
                return cnt;
        }
        return -1;
    }
};
