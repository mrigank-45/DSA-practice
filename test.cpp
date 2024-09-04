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
        return queryTree(0, 0, n - 1, l, r);
    }

    void update(int idx, int val)
    {
        nums[idx] = val;
        updateTree(0, 0, n - 1, idx);
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

    int queryTree(int node, int start, int end, int l, int r)
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
        return queryTree(leftChild, start, mid, l, r) + queryTree(rightChild, mid + 1, end, l, r);
    }

    void updateTree(int node, int start, int end, int idx)
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
                updateTree(leftChild, start, mid, idx);
            }
            else
            {
                updateTree(rightChild, mid + 1, end, idx);
            }
            tree[node] = tree[leftChild] + tree[rightChild];
        }

        // Update the peaks for the neighboring elements
        if (idx > start)
        {
            int leftMid = (start + end) / 2;
            if (idx <= leftMid)
                updateTree(node, start, leftMid, idx - 1);
            else
                updateTree(node, leftMid + 1, end, idx + 1);
        }
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

int main() {
    vector<int> nums = {4, 1, 4, 2, 1, 5};
    vector<vector<int>> queries = {{2, 2, 4}, {1, 0, 2}, {1, 0, 4}};
    Solution sol;
    vector<int> result = sol.countOfPeaks(nums, queries);

    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
