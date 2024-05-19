#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *root, long long &ans, long long temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans = max(ans, temp * root->data);
            return;
        }

        if (root->left)
        {
            solve(root->left, ans, temp * root->data);
        }

        if (root->right)
        {
            solve(root->right, ans, temp * root->data);
        }
    }
    long long findMaxScore(Node *root)
    {
        long long ans = 1;

        solve(root, ans, 1);
    }
};
