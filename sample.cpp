#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(vector<int> &nums) : n(nums.size()), nums(nums)
    {
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int val)
    {
        nums[idx] = val;
        update(0, 0, n - 1, idx);
    }

private:
    int n;
    vector<int> nums;
    vector<int> tree;

    bool isPeak(int i)
    {
        if (i <= 0 || i >= n - 1)
            return false;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = isPeak(start) ? 1 : 0;
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        return query(leftChild, start, mid, l, r) + query(rightChild, mid + 1, end, l, r);
    }

    void update(int node, int start, int end, int idx)
    {
        if (start == end)
        {
            tree[node] = isPeak(start) ? 1 : 0;
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (idx <= mid)
            {
                update(leftChild, start, mid, idx);
            }
            else
            {
                update(rightChild, mid + 1, end, idx);
            }
            tree[node] = tree[leftChild] + tree[rightChild];
        }
        // Update the neighbors as well if necessary
        if (idx > 0)
            update(node, start, end, idx - 1);
        if (idx < n - 1)
            update(node, start, end, idx + 1);
    }
};

class Solution
{
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        SegmentTree segTree(nums);
        vector<int> result;

        for (const auto &query : queries)
        {
            if (query[0] == 1)
            { // Query type 1: count peaks in range [li, ri]
                int li = query[1], ri = query[2];
                result.push_back(segTree.query(li, ri));
            }
            else if (query[0] == 2)
            { // Query type 2: update nums[indexi] to vali
                int indexi = query[1], vali = query[2];
                segTree.update(indexi, vali);
            }
        }

        return result;
    }
};
