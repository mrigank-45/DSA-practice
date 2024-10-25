#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    void solve(TreeNode *root, string s)
    {
        if (root == NULL)
        {
            return;
        }
        s += root->val + 'a';
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(s);
            return;
        }
        solve(root->left, s);
        solve(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        for(int i =0; i<ans.size(); i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        return ans[0];
        
    }
};