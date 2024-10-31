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
    int solve(TreeNode *root, int maxVal)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ans = 0;
        if (root->val >= maxVal)
            ans++;
        ans += solve(root->left, max(maxVal, root->val));
        ans += solve(root->right, max(maxVal, root->val));
        return ans;
    }
    int goodNodes(TreeNode *root)
    {
        return solve(root, INT_MIN);
    }
};
