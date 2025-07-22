#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> houses, vector<int> heaters, int k, int n)
    {
        vector<vector<int>> res;

        int first = max(heaters[0] - k, 0);
        int second = heaters[0] + k;

        for(int i = 1; i < heaters.size(); i++)
        {
            int a = max(heaters[i] - k, 0);
            int b = heaters[i] + k;
            if(a <= second)
            {
                second = max(second, b);
            }
            else
            {
                res.push_back({first, second});
                first = a;
                second = b;
            }
        }
        res.push_back({first, second});

        for(int i = 0; i < houses.size(); i++)
        {
            bool found = false;
            for(int j = 0; j < res.size(); j++)
            {
                if(houses[i] >= res[j][0] && houses[i] <= res[j][1])
                {
                    found = true;
                }
            }
            if(!found) return false;
        }
        return true;
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int s = 0, e = max(heaters[heaters.size() - 1], houses[n - 1]);
        int ans = e;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (possible(houses, heaters, mid, n))
            {
                ans = min(ans, mid);
                e = mid;
                if (s == e)
                    break;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
