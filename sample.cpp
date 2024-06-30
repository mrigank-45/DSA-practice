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
    bool isCousins(TreeNode *root, int x, int y)
    {
        map<int, pair<int, int>> mp;

        mp[root->val] = {0, -1};

        queue<TreeNode *> q;

        q.push(root);

        int d = 0;

        while (!q.empty())
        {
            int size = q.size();
            d++;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                {
                    mp[node->left->val] = {d, node->val};
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    mp[node->right->val] = {d, node->val};
                    q.push(node->right);
                }
            }
        }
        if (mp[x].first == mp[y].first && mp[x].second != mp[y].second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
