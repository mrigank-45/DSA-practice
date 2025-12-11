// we could do it like we did in binary tree as well but here we use the BST property.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case
        if (root == NULL)
        {
            return NULL;
        }

        if ((p->val < root->val) && (q->val < root->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        else if ((p->val > root->val) && (q->val > root->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            // we reached our ans
            return root;
        }
    }
};
