// Lowest Common Ancister (leetcode): using recursion
// Alternate approach: We can also solve this by finding paths to both node and then see the first common element from back.

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
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        // base case
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *leftAns = lca(root->left, n1, n2);
        Node *rightAns = lca(root->right, n1, n2);

        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return NULL;
        }
    }
};
