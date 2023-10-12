#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct info
{
    int isbst;
    int size;
    int min;
    int max;
};

struct info bst(struct Node *root, int &ans)
{
    struct info x;
    if (root == NULL)
    {
        x.isbst = 1;
        x.size = 0;
        x.min = 1000000;
        x.max = 0;
        return x;
    }

    struct info left = bst(root->left, ans);
    struct info right = bst(root->right, ans);

    x.size = 1 + left.size + right.size;
    x.max = max(root->data, right.max);
    x.min = min(root->data, left.min);

    if (left.isbst == 1 && right.isbst == 1 && root->data > left.max && root->data < right.min)
    {
        x.isbst = 1;
    }
    else
    {
        x.isbst = 0;
    }

    if (x.isbst)
    {
        ans = max(ans, x.size);
    }
    return x;
};

class Solution
{
public:
    int largestBst(Node *root)
    {
        int maxSize = 0;
        info temp = bst(root, maxSize);
        return maxSize;
    }
};
