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
    int solve(TreeNode *root, int prev)
    {
        if (root == NULL)
            return 0;

        int ans = 0;

        // not pick
        ans = max(ans, solve(root->left, 0) + solve(root->right, 0));

        // pick
        if (prev == 0)
        {
            ans = max(ans, root->val + solve(root->left, 1) + solve(root->right, 1));
        }

        return ans;
    }
    int rob(TreeNode *root)
    {
        return solve(root, 0);
    }
};
