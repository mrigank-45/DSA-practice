#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> tree;
    long long size;

    void SegmentTree(vector<long long> &array)
    {
        size = array.size();
        tree.resize(4 * size);
        buildTree(array, 0, 0, size - 1);
    }

    // TC: O(n)
    void buildTree(vector<long long> &array, long long treeIndex, long long left, long long right)
    {
        if (left == right)
        {
            tree[treeIndex] = array[left];
            return;
        }
        long long mid = left + (right - left) / 2;
        buildTree(array, 2 * treeIndex + 1, left, mid);
        buildTree(array, 2 * treeIndex + 2, mid + 1, right);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    // TC: O(logn)
    long long query(long long treeIndex, long long low, long long high, long long queryLeft, long long queryRight)
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
        long long mid = low + (high - low) / 2;
        long long left = query(2 * treeIndex + 1, low, mid, queryLeft, queryRight);
        long long right = query(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight);

        return left + right;
    }

    // TC: O(logn)
    void rangeUpdate(long long treeIndex, long long low, long long high, long long queryLeft, long long queryRight)
    {
        if (low == high)
        {
            long long val = tree[treeIndex];
            tree[treeIndex] = countDigits(val);
            return;
        }
        // out of range
        if (high < queryLeft || low > queryRight)
        {
            return;
        }

        long long mid = low + (high - low) / 2;
        rangeUpdate(2 * treeIndex + 1, low, mid, queryLeft, queryRight);
        rangeUpdate(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    long long querySum(long long left, long long right)
    {
        return query(0, 0, size - 1, left, right);
    }

    void rangeChange(long long left, long long right)
    {
        rangeUpdate(0, 0, size - 1, left, right);
    }

    long long countDigits(long long num)
    {
        if (num == 0)
            return 1;
        long long count = 0;
        while (num > 0)
        {
            num /= 10;
            count++;
        }
        return count;
    }
    vector<long long> RangeSumDigits(int n, vector<int> &arr, long long Q, vector<vector<int>> &Queries)
    {
        vector<long long> array(n);
        for (int i = 0; i < n; i++)
        {
            array[i] = (long long)arr[i];
        }
        SegmentTree(array);
        vector<long long> ans;

        // Process each query
        for (const auto &query : Queries)
        {
            long long type = query[0];
            long long l = query[1] - 1;
            long long r = query[2] - 1;

            if (type == 1)
            {
                // Change the value of the given index
                rangeChange(l, r);
            }
            else if (type == 2)
            {
                // Query the sum of digits in the given range
                ans.push_back(querySum(l, r));
            }
        }

        return ans;
    }
};
