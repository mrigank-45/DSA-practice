#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> nextSmallerElement1(vector<int> &arr, int n)
    {
        stack<pair<int, int>> s;
        s.push({-1, -1});
        vector<pair<int, int>> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top().first >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push({curr, i});
        }
        return ans;
    }
    vector<pair<int, int>> nextSmallerElement2(vector<int> &arr, int n)
    {
        stack<pair<int, int>> s;
        s.push({-1, -1});
        vector<pair<int, int>> ans(n);

        for (int i = 0; i <= n - 1; i++)
        {
            int curr = arr[i];
            while (s.top().first >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push({curr, i});
        }
        return ans;
    }

    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<pair<int, int>> ans1 = nextSmallerElement1(arr, n);
        vector<pair<int, int>> ans2 = nextSmallerElement2(arr, n);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (ans1[i].first == -1 && ans2[i].first != -1)
            {
                ans.push_back(ans2[i].second);
            }
            else if (ans2[i].first == -1 && ans1[i].first != -1)
            {
                ans.push_back(ans1[i].second);
            }
            else if (ans1[i].first == -1 && ans2[i].first == -1)
            {
                ans.push_back(-1);
            }
            else
            {
                if (abs(ans1[i].second - i) < abs(ans2[i].second - i))
                {
                    ans.push_back(ans1[i].second);
                }
                else if(abs(ans1[i].second - i) > abs(ans2[i].second - i))
                {
                    ans.push_back(ans2[i].second);
                }
                else{
                    if(ans1[i].first < ans2[i].first){
                        ans.push_back(ans1[i].second);
                    }
                    else{
                        ans.push_back(ans2[i].second);
                    }
                }
            }
        }
        return ans;
    }
};
