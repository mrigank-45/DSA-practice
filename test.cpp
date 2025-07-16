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
        int sum1 = 0, sum2 = 0;
        if (root->left)
            sum1 = solve(root->left, 0);
        if (root->right)
            sum2 = solve(root->right, 0);

        ans = max(ans, sum1 + sum2);

        // pick
        if (prev == 0)
        {
            int sum1 = 0, sum2 = 0;
            if (root->left)
                sum1 = solve(root->left, 1);
            if (root->right)
                sum2 = solve(root->right, 1);
            ans = max(ans, root->val + sum1 + sum2);
        }

        return ans;
    }
    int rob(TreeNode *root)
    {
        return solve(root, 0);
    }
};
