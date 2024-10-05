#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        bool flag = false;

        int i = 0;
        while (i < n)
        {
            if (flag)
            {
                while (i < n)
                {
                    ans.push_back(intervals[i]);
                    i++;
                }
                break;
            }
            if (intervals[i][1] >= l)
            {
                vector<int> temp(2);

                if (l <= intervals[i][0])
                {
                    temp[0] = l;
                }
                else
                {
                    temp[0] = intervals[i][0];
                }
                while (i < n)
                {
                    if (intervals[i][1] >= r)
                    {
                        if (r >= intervals[i][0])
                        {
                            temp[1] = intervals[i][1];
                            i++;
                        }
                        else
                        {
                            temp[1] = r;
                        }
                        flag = true;
                        ans.push_back(temp);
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
                if (!flag)
                {
                    temp[1] = r;
                    ans.push_back(temp);
                    flag = true;
                    break;
                }
            }
            else
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }

        if (!flag)
        {
            ans = intervals;
            ans.push_back(newInterval);
        }

        return ans;
    }
};
