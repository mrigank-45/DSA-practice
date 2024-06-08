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
    string solve(TreeNode *root, map<TreeNode *, int> &ans, unordered_map<string, int> &mp)
    {
        if (root == NULL)
        {
            return "";
        }
        string temp = to_string(root->val);
        temp = temp + solve(root->left, ans, mp) + solve(root->right, ans, mp);
        if (mp[temp] == 1)
        {
            ans[root]++;
        }
        else
        {
            mp[temp]++;
        }

        return temp;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        map<TreeNode *, int> ans;
        unordered_map<string, int> mp;
        solve(root, ans, mp);
        
        vector<TreeNode *> res;

        for (auto i : ans)
        {
            if (i.second > 0)
            {
                res.push_back(i.first);
            }
        }
    }
};
