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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if(root == NULL) return {{}};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            vector<int> ans(size);

            for (int i = 0; i < size; i++)
            {

                TreeNode *frontNode = q.front();
                q.pop();

                ans[i] = frontNode->val;

                if (frontNode->left)
                {
                    q.push(frontNode->left);
                }

                if (frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }

            res.push_back(ans);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
