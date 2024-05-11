#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool sameTree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        if (root == NULL || subRoot == NULL)
        {
            return false;
        }

        if (root->val == subRoot->val)
        {
            if (sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right))
            {
                return true;
            }
        }
        return false;
    }

    bool solve(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        if (root == NULL || subRoot == NULL)
        {
            return false;
        }

        if (root->val == subRoot->val)
        {
            if (sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right))
            {
                return true;
            }
        }
        return solve(root->left, subRoot) || solve(root->right, subRoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return solve(root, subRoot);
    }
};
