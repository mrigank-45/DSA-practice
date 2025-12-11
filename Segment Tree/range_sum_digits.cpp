// Range sum digits (gfg)
#include <bits/stdc++.h>
using namespace std;

// number of digits in a number can be max 10, so if changed[i] >= 3, then we don't need to change it anymore, hence we are tracking it.

class Solution
{
private:
    int change(int num)
    {
        int ans = 0;
        while (num)
        {
            ans++;
            num /= 10;
        }
        return ans;
    }
    const int MAXN = 4 * 100005;
    vector<long long> tree;
    vector<int> changed;
    void build(int index, int low, int high, vector<long long> &A)
    {
        if (low == high)
        {
            tree[index] = A[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, A);
        build(2 * index + 2, mid + 1, high, A);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    long long query(int index, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return 0;
        if (l <= low && high <= r)
            return tree[index];
        int mid = (low + high) >> 1;
        return query(2 * index + 1, low, mid, l, r) + query(2 * index + 2, mid + 1, high, l, r);
    }
    void update(int index, int low, int high, int l, int r)
    {
        if (r < low || high < l || changed[index] >= 3)
            return;
        if (low == high)
        {
            tree[index] = change(tree[index]);
            changed[index]++;
            return;
        }
        if (l <= low && high <= r)
            changed[index]++;
        int mid = (low + high) / 2;
        update(2 * index + 1, low, mid, l, r);
        update(2 * index + 2, mid + 1, high, l, r);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

public:
    vector<long long> RangeSumDigits(int n, vector<int> arr, int Q,
                                     vector<vector<int>> Queries)
    {
        vector<long long> A(n);
        for (int i = 0; i < n; i++)
        {
            A[i] = arr[i];
        }
        tree.resize(4 * n);
        changed.resize(4 * n);
        build(0, 0, n - 1, A);

        vector<long long> ans;
        for (auto &qq : Queries)
        {
            if (qq[0] == 1)
            {
                update(0, 0, n - 1, qq[1] - 1, qq[2] - 1);
            }
            else
            {
                ans.push_back(query(0, 0, n - 1, qq[1] - 1, qq[2] - 1));
            }
        }
        return ans;
    }
};
