#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    vector<int> lazy;
    int size;

public:
    SegmentTree(vector<int> &array)
    {
        size = array.size();
        tree.resize(4 * size);
        lazy.resize(4 * size, 0);
        buildTree(array, 0, 0, size - 1);
    }

private:
    // TC: O(n)
    void buildTree(vector<int> &array, int treeIndex, int left, int right)
    {
        if (left == right)
        {
            tree[treeIndex] = array[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(array, 2 * treeIndex + 1, left, mid);
        buildTree(array, 2 * treeIndex + 2, mid + 1, right);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    // TC: O(logn)
    int query(int treeIndex, int low, int high, int queryLeft, int queryRight)
    {
        // in range
        if (queryLeft <= low && high <= queryRight)
        {
            return tree[treeIndex];
        }
        // out of range
        if (high < queryLeft || low > queryRight)
        {
            return 0;
        }
        // partially in range
        int mid = low + (high - low) / 2;
        int left = query(2 * treeIndex + 1, low, mid, queryLeft, queryRight);
        int right = query(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight);

        return left + right;
    }

    void pointUpdate(int treeIndex, int low, int high, int index, int value)
    {
        if (low == high)
        {
            tree[treeIndex] = value;
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid)
        {
            pointUpdate(2 * treeIndex + 1, low, mid, index, value);
        }
        else
        {
            pointUpdate(2 * treeIndex + 2, mid + 1, high, index, value);
        }
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    // TC: O(logn)
    void rangeUpdate(int treeIndex, int low, int high, int queryLeft, int queryRight, int value)
    {
        // update pending lazy updates
        if (lazy[treeIndex] != 0)
        {
            tree[treeIndex] += lazy[treeIndex] * (high - low + 1);
            if (low != high) // not a leaf node
            {
                lazy[2 * treeIndex + 1] += lazy[treeIndex];
                lazy[2 * treeIndex + 2] += lazy[treeIndex];
            }
            lazy[treeIndex] = 0;
        }
        // out of range
        if (high < queryLeft || low > queryRight)
        {
            return;
        }
        // in range
        if (queryLeft <= low && high <= queryRight)
        {
            tree[treeIndex] += value * (high - low + 1);
            if (low != high)
            {
                lazy[2 * treeIndex + 1] += value;
                lazy[2 * treeIndex + 2] += value;
            }
            return;
        }
        // partially in range
        int mid = low + (high - low) / 2;
        rangeUpdate(2 * treeIndex + 1, low, mid, queryLeft, queryRight, value);
        rangeUpdate(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight, value);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    // TC: O(logn)
    int queryLazy(int treeIndex, int low, int high, int queryLeft, int queryRight)
    {
        // update pending lazy updates
        if (lazy[treeIndex] != 0)
        {
            tree[treeIndex] += lazy[treeIndex] * (high - low + 1);
            if (low != high)
            {
                lazy[2 * treeIndex + 1] += lazy[treeIndex];
                lazy[2 * treeIndex + 2] += lazy[treeIndex];
            }
            lazy[treeIndex] = 0;
        }
        // out of range
        if (high < queryLeft || low > queryRight)
        {
            return 0;
        }
        // in range
        if (queryLeft <= low && high <= queryRight)
        {
            return tree[treeIndex];
        }
        // partially in range
        int mid = low + (high - low) / 2;
        int left = queryLazy(2 * treeIndex + 1, low, mid, queryLeft, queryRight);
        int right = queryLazy(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight);
        return left + right;
    }

public:
    // *********functions to call************
    int querySum(int left, int right)
    {
        return query(0, 0, size - 1, left, right);
    }
    int querySumLazy(int left, int right)
    {
        return queryLazy(0, 0, size - 1, left, right);
    }
    void rangeAdd(int left, int right, int value)
    {
        rangeUpdate(0, 0, size - 1, left, right, value);
    }
    void pointUpdate(int index, int value)
    {
        pointUpdate(0, 0, size - 1, index, value);
    }
};

int main()
{
    vector<int> array = {1, 3, 2, 5, 4, 6};
    SegmentTree st(array);
    cout << st.querySum(1, 5) << endl; // 20

    st.rangeAdd(1, 3, 3);
    cout << st.querySumLazy(1, 5) << endl; // 29
    st.rangeAdd(3, 4, 2);
    cout << st.querySumLazy(1, 5) << endl; // 33
}
