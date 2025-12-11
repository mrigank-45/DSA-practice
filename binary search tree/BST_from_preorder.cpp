// we can also first sort the preorder given to get the inorder, then construct using the preorder and inorder like we used
// to do in binary tree but that that is O(nlogn)
// This solution uses range concept of BST and solve it in O(n)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *construct(int &index, int min, int max, vector<int> &preorder)
    {
        if (index >= preorder.size())
            return NULL;
        if (preorder[index] < min || preorder[index] > max)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[index]);
        index++;
        root->left = construct(index, min, root->val, preorder);
        root->right = construct(index, root->val, max, preorder);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return construct(index, INT_MIN, INT_MAX, preorder);
    }
};
