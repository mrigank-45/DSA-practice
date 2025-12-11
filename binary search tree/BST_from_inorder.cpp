// used when we have to merge 2 BST

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *solve(int s, int e, vector<int> &inorder)
    {
        if (s > e)
        {
            return NULL;
        }
        int mid = (s + e) / 2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = solve(s, mid - 1, inorder);
        root->right = solve(mid + 1, e, inorder);
        return root;
    }
    TreeNode *bstFromInorder(vector<int> &inorder)
    {
        int s = 0;
        int e = inorder.size() - 1;
        return solve(s, e, inorder);
    }
};
