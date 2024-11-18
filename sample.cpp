#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    int findSum(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }

        int left = findSum(root->left);
        int right = findSum(root->right);
        return root->data + left + right;
    }
    bool isSumTree(Node *root)
    {
        if(root == NULL)
        {
            return true;
        }
        int sum = findSum(root->left) + findSum(root->right);

        if (root->data == sum)
        {
            return true;
        }
        return false;
    }
};
