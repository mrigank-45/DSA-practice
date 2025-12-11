// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up
// all the values along the path equals targetSum.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    void solve(Node *node, vector<int> &sums, int sum)
    {
        if (node == NULL)
        {
            return;
        }
        if ((node->left == NULL) && (node->right == NULL))
        {
            sum += node->val;
            sums.push_back(sum);
            return;
        }
        sum += node->val;
        solve(node->left, sums, sum);
        solve(node->right, sums, sum);
        return;
    }

    bool hasPathSum(Node *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        vector<int> sums;
        solve(root, sums, 0);
        for (int i = 0; i < sums.size(); i++)
        {
            cout << sums[i] << " ";
            if (sums[i] == targetSum)
            {
                return true;
            }
        }
        return false;
    }
};
