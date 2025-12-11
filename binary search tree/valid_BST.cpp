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
    bool checkBST(TreeNode *root, long min, long max)
    {

        // base case
        if (root == NULL)
        {
            return true;
        }

        if (root->val > min && root->val < max)
        {
            // recursion calls
            bool left = checkBST(root->left, min, root->val);
            bool right = checkBST(root->right, root->val, max);
            return left && right;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        bool ans = checkBST(root, LONG_MIN, LONG_MAX);
        return ans;
    }
};
