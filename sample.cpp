#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
        left = right = NULL;
    }
};

class Solution
{
public:
    pair<bool, int> checkBST(Node *root, long mini, long maxi, int k)
    {
        if (root == NULL)
        {
            return {true, 0};
        }

        if (root->data > mini && root->data < maxi)
        {
            pair<bool, int> left = checkBST(root->left, mini, root->data, k + 1);
            pair<bool, int> right = checkBST(root->right, root->data, maxi, k + 1);
            return {left.first && right.first,  left.second + right.second + 1};
        }
        else
        {
            return {false, k + 1};
        }
    }
    int largestBst(Node *root)
    {
        pair<bool, int> p = checkBST(root, LONG_MIN, LONG_MAX, 0);
        if(p.first)
            return p.second;
        else
            return 1;
    }
};
