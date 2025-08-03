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
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void populate(TreeNode *root, unordered_map<int, int> &m)
    {
        if (root == nullptr)
            return;
        populate(root->left, m);
        root->val = m[root->val];
        populate(root->right, m);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        unordered_map<int, int> m;
        inorder(root);
        int sum = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            sum += v[i];
            m[v[i]] = sum;
        }
        populate(root, m);
        return root;
    }
};
