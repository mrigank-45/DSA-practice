// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path
// equals targetSum.
// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes
// to child nodes).

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
    int count = 0;

    void solve(TreeNode *&root, int &targetSum, long long int sum)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;
        if (sum == targetSum)
        {
            count++;
        }
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
    }

    int pathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return 0;

        long long int sum = 0;
        solve(root, targetSum, sum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};
