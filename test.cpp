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
    void mapping(TreeNode *root, map<TreeNode *, TreeNode *> &mp)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left)
        {
            mp[root->left] = root;
            mapping(root->left, mp);
        }

        if (root->right)
        {
            mp[root->right] = root;
            mapping(root->right, mp);
        }
    }
    void solve(TreeNode *root, map<TreeNode *, TreeNode *> &mp, int &ans, TreeNode *prev, map<TreeNode *, bool> &visited, int sum = 0)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;
        ans = max(ans, sum);

        if (root->left && root->left != prev)
        {
            solve(root->left, mp, ans, root, visited, sum);
            if (!visited[root->left])
            {
                visited[root->left] = true;
                solve(root->left, mp, ans, NULL, visited, 0);
            }
        }

        if (root->right && root->right != prev)
        {
            solve(root->right, mp, ans, root, visited, sum);
            if (!visited[root->right])
            {
                visited[root->right] = true;
                solve(root->right, mp, ans, NULL, visited, 0);
            }
        }

        if (mp[root] && mp[root] != prev)
        {
            solve(mp[root], mp, ans, root, visited, sum);
            if (!visited[mp[root]])
            {
                visited[mp[root]] = true;
                solve(mp[root], mp, ans, NULL, visited, 0);
            }
        }
    }
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;

        // node to parent node
        map<TreeNode *, TreeNode *> mp;
        mp[root] = NULL;
        mapping(root, mp);

        map<TreeNode *, bool> visited;
        visited[root] = true;
        solve(root, mp, ans, NULL, visited, 0);

        return ans;
    }
};
