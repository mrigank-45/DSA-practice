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
    int mn;
    int mx;
};
struct info bst(struct Node *root,int &ans)
{
    struct info x;
    if (root == NULL)
    {
        x.isbst = 1;
        x.size = 0;
        x.mn = 1000000;
        x.mx = 0;
        return x;
    }
    struct info left = bst(root->left,ans);
    struct info right = bst(root->right,ans);
    x.size = 1 + left.size + right.size;
    x.mx = max(root->data, right.mx);
    x.mn = min(root->data, left.mn);
    if (left.isbst == 1 && right.isbst == 1 && root->data > left.mx && root->data < right.mn)
    {
        x.isbst = 1;
    }
    else
    {
        x.isbst = 0;
    }
    if(x.isbst){
        ans = max(ans,x.size);
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
