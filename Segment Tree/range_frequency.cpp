// Range Frequency Queries
#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery
{
public:
    int n;
    vector<map<int, int>> seg; // stores occurance of each element
    void makeTree(int low, int high, vector<int> &arr, int i)
    {
        if (low == high)
        {
            map<int, int> m;
            m[arr[low]]++;
            seg[i] = m;
            return;
        }
        int mid = (low + high) >> 1;
        makeTree(low, mid, arr, 2 * i);
        makeTree(mid + 1, high, arr, 2 * i + 1);
        map<int, int> m;
        m = seg[2 * i];
        for (auto it : seg[2 * i + 1])
        {
            if (m.find(it.first) == m.end())
                m[it.first] = it.second;
            else
                m[it.first] += it.second;
        }
        seg[i] = m;
    }
    RangeFreqQuery(vector<int> &arr)
    {
        n = arr.size();
        map<int, int> m;
        seg = vector<map<int, int>>(4 * n + 1, m);
        makeTree(0, n - 1, arr, 1);
    }
    int query(int node, int l, int r, int ql, int qr, int val)
    {
        if (l > r || ql > r || l > qr)
            return 0;
        if (ql <= l && r <= qr)
            return seg[node][val];
        int mid = (l + r) >> 1;
        int left = query(node + node, l, mid, ql, qr, val);
        int right = query(node + node + 1, mid + 1, r, ql, qr, val);
        return left + right;
    }
    int query(int left, int right, int value)
    {
        return query(1, 0, n - 1, left, right, value);
    }
};
