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
    vector<int> ans;
    void solve(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(sum);
            return;
        }
        solve(root->left, sum);
        solve(root->right, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        solve(root, 0);
        int res = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            res += ans[i];
        }
        return res;
    }
};
