// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left 
// subtree's value and its right subtree's value. Else return false.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *root)
    {

        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        int leftSum = leftAns.second;
        int rightSum = rightAns.second;

        bool condn = root->data == leftSum + rightSum;

        pair<bool, int> ans;

        if (isLeftSumTree && isRightSumTree && condn)
        {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first;
    }
};
