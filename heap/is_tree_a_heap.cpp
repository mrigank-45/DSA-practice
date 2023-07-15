// Given a binary tree, check if the tree is heap or not.
// zero based indexing

#include <bits/stdc++.h>
using namespace std;

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int countNodes(struct Node *root)
    {
        if (root == NULL)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
    bool CBT(struct Node *root, int count, int index)
    {
        if (root == NULL)
            return true;
        if (index >= count)
        {
            return false;
        }
        bool left = CBT(root->left, count, index * 2 + 1);
        bool right = CBT(root->right, count, index * 2 + 2);
        return (left && right);
    }

    bool maxOrder(struct Node *root)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
            return root->data > root->left->data;

        bool left = maxOrder(root->left);
        bool right = maxOrder(root->right);
        bool current = root->data > root->left->data && root->data > root->right->data;
        return left && right && current;
    }
    bool isHeap(struct Node *tree)
    {
        int count = countNodes(tree);
        int index = 0;
        if (CBT(tree, count, index) && maxOrder(tree))
            return true;
        else
            return false;
    }
};
