// Binary Tree Maximum Path Sum | Leetcode
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
    int dfs(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        // neglect left or right sum if it is less than 0
        int lMax = max(dfs(root->left, ans), 0);
        int rMax = max(dfs(root->right, ans), 0);

        ans = max(ans, lMax + rMax + root->val);

        return (max(lMax, rMax) + root->val);
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
