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
    map<int, int> mp;

    void levelOrderTransversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (!q.empty())
        {
            int size = q.size();

            int ans = 0;
            for (int i = 0; i < size; i++)
            {

                TreeNode *frontTreeNode = q.front();
                q.pop();

                ans += frontTreeNode->val;

                if (frontTreeNode->left)
                    q.push(frontTreeNode->left);

                if (frontTreeNode->right)
                    q.push(frontTreeNode->right);
            }
            mp[i] = ans;
            i++;
        }
    }
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        levelOrderTransversal(root);

        int maxSum = INT_MIN;
        int maxLevel = 0;
        for (auto i : mp)
        {
            if (i.second > maxSum)
            {
                maxSum = i.second;
                maxLevel = i.first;
            }
        }

        return maxLevel;
    }
};
