#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> possible;
        for (auto it : mp)
        {
            if (it.second >= 2)
            {
                possible.push_back(it.first);
            }
        }
        if (possible.size() == 0)
        {
            int dis = nums.size() - 1;
            if (dis % 2 == 0)
            {
                return (dis / 2);
            }
            else
            {
                return (dis / 2 + 1);
            }
        }

        int minAns = INT_MAX;
        for (int j = 0; j < possible.size(); j++)
        {
            vector<int> index;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == possible[j])
                {
                    index.push_back(i);
                }
            }

            int dis = index[0] + (nums.size() - 1) - (index[index.size() - 1]);

            for (int i = 1; i < index.size(); i++)
            {
                if ((index[i] - index[i - 1]) > dis)
                {
                    dis = index[i] - index[i - 1] - 1;
                }
            }

            minAns = min(minAns, (dis + 1) / 2);
        }

        return minAns;
    }
};
