#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] <= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    long long numberOfSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        long long ans = 0;
        vector<int> nextGreater = nextGreaterElement(nums, n);

        for (auto it : mp)
        {
            if (it.second.size() < 2)
                continue;

            vector<int> v = it.second;
            for (int i = 0; i < v.size() - 1; i++)
            {
                if (nextGreater[v[i]] == -1)
                {
                    ans += v.size() - i - 1;
                    continue;
                }

                for (int j = i + 1; j < v.size(); j++)
                {
                    if (nextGreater[v[i]] == -1 || nextGreater[v[i]] > v[j])
                        ans++;
                }
            }
        }

        return ans + n;
    }
};
