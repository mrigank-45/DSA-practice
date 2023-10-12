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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        // {level, value of node}
        map<int, int> m;

        // {node,level}
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            if (m.find(p.second) == m.end())
            {
                m[p.second] = p.first->val;
            }
            if (p.first->right)
            {
                q.push(make_pair(p.first->right, p.second + 1));
            }
            if (p.first->left)
            {
                q.push(make_pair(p.first->left, p.second + 1));
            }
            // for left view, go to left first then right
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
