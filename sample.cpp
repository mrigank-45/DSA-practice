#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void solve(vector<int> &arr, int i, int maxi, int prev, int p, int n, vector<int> prefix)
    {
        // base case
        if (p == 0)
        {
            int sum = (prev == -1 ? prefix[n - 1] : prefix[n - 1] - prefix[prev]);
            res.push_back(max(maxi, sum));
            return;
        }
        if (i == n - 1)
        {
            return;
        }

        // partition
        int sum = (prev == -1 ? prefix[i] : prefix[i] - prefix[prev]);
        solve(arr, i + 1, max(maxi, sum), i, p - 1, n, prefix);

        // not partition
        solve(arr, i + 1, maxi, prev, p, n, prefix);

        return;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        solve(nums, 0, 0, -1, k - 1, n, prefix);

        sort(res.begin(),res.end());
        return res[0];
    }
};
