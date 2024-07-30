#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    vector<int> tree;
    int size;
    NumArray(vector<int> &nums)
    {
        size = nums.size();
        tree.resize(4 * size);
        buildTree(nums, 0, 0, size - 1);
    }

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

    void update(int index, int val)
    {
        pointUpdate(0, 0, size - 1, index, val);
    }

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

    int sumRange(int left, int right)
    {
        return query(0, 0, size - 1, left, right);
    }
};
