#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int size;

public:
    SegmentTree(vector<int> &array)
    {
        size = array.size();
        tree.resize(4 * size);
        buildTree(array, 0, 0, size - 1);
    }

private:
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
        tree[treeIndex] = max(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
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
            return INT_MIN;
        }
        // partially in range
        int mid = low + (high - low) / 2;
        int left = query(2 * treeIndex + 1, low, mid, queryLeft, queryRight);
        int right = query(2 * treeIndex + 2, mid + 1, high, queryLeft, queryRight);

        return max(left, right);
    }

public:
    int query(int left, int right)
    {
        return query(0, 0, size - 1, left, right);
    }
};

int main()
{
    vector<int> array = {1, 3, 2, 5, 4, 6};
    SegmentTree st(array);
    cout << st.query(1, 5) << endl; // 6
    return 0;
}
