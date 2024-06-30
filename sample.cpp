#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    bool flag = 1;
    int solve(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        if (root->data != leftSum + rightSum)
        {
            flag = 0;
        }

        return root->data + leftSum + rightSum;
    }
    bool isSumTree(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }

        int temp = solve(root);

        return flag;
    }
};
