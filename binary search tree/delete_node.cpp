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
    int maxVal(TreeNode *root)
    {
        TreeNode *temp = root;
        if (temp == NULL)
        {
            return -1;
        }

        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->val;
    }
    TreeNode *deleteNode(TreeNode *root, int target)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == target)
        {
            // isi ko delete krna h
            // 4 cases
            if (root->left == NULL && root->right == NULL)
            {
                // leaf node
                // delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *child = root->right;
                // delete root;
                return child;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *child = root->left;
                // delete root;
                return child;
            }
            else
            {
                // both child
                // find inorder predecessor inb left subtree
                int inorderPre = maxVal(root->left);
                // replace root->val value with inorder predecessor
                root->val = inorderPre;
                // delete inorder predecessor from left subtree
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }
        else if (target > root->val)
        {
            // right jana chahiye
            root->right = deleteNode(root->right, target);
        }
        else if (target < root->val)
        {
            // left jana chahioye
            root->left = deleteNode(root->left, target);
        }
        return root;
    }
};
