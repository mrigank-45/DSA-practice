#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        map<pair<int, int>, char> mp;
        map<char, int> vis;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            mp[{points[i][0], points[i][1]}] = s[i];
        }
        int ans = 0, len = 2;
        pair<int, int> p1 = {-1, 1};
        pair<int, int> p2 = {1, -1};

        while (vis.size() <= n)
        {
            if (vis.size() == n)
                return ans;
            int x = p1.first;
            int y = p1.second;
            int temp = ans;
            for (int i = x; i <= x + len; i++)
            {
                if (mp.find({i, y}) != mp.end())
                {
                    cout<<"found: "<<mp[{i, y}]<<endl;
                    if (vis[mp[{i, y}]])
                    {
                        return ans;
                    }
                    else
                    {
                        vis[mp[{i, y}]] = 1;
                        temp++;
                    }
                }
            }
            for (int i = y; i >= y - len; i--)
            {
                if (mp.find({x, i}) != mp.end())
                {
                    cout<<"found: "<<mp[{i, y}]<<endl;

                    if (vis[mp[{x, i}]])
                    {
                        return ans;
                    }
                    else
                    {
                        vis[mp[{x, i}]] = 1;
                        temp++;
                    }
                }
            }

            x = p2.first;
            y = p2.second;

            for (int i = x; i > x - len; i--)
            {
                if (mp.find({i, y}) != mp.end())
                {
                    cout<<"found: "<<mp[{i, y}]<<endl;

                    if (vis[mp[{i, y}]])
                    {
                        return ans;
                    }
                    else
                    {
                        vis[mp[{i, y}]] = 1;
                        temp++;
                    }
                }
            }

            for (int i = y; i < y + len; i++)
            {
                if (mp.find({x, i}) != mp.end())
                {
                    cout<<"found: "<<mp[{i, y}]<<endl;

                    if (vis[mp[{x, i}]])
                    {
                        return ans;
                    }
                    else
                    {
                        vis[mp[{x, i}]] = 1;
                        temp++;
                    }
                }
            }
            ans = temp;
            cout << "p1: " << p1.first << " " << p1.second << endl;
            cout << "p2: " << p2.first << " " << p2.second << endl;
            cout << "ans: " << ans << endl;
            len += 2;
            p1.first--;
            p1.second--;
            p2.first++;
            p2.second++;
                }
        return ans;
    }
};
