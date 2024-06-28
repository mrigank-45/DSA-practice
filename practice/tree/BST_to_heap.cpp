// BST to max heap

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
    vector<int> arr;
    int i = 0;

    void inorderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left);
        arr.push_back(root->data);
        inorderTraversal(root->right);
    }

    void BSTToMaxHeap(Node *root)
    {
        if (root == NULL)
            return;

        BSTToMaxHeap(root->left);

        BSTToMaxHeap(root->right);

        // copy data at index 'i' of 'arr' to the node
        root->data = arr[i];
        i++;
    }

    void convertToMaxHeapUtil(Node *root)
    {
        inorderTraversal(root);
        BSTToMaxHeap(root);
    }
};
