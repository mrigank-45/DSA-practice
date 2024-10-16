#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution
{
public:
    void solve(Node *root, Node *head)
    {
        if (root == NULL)
            return;

        solve(root->left, head);

        if(head == NULL)
        {
            head = root;
        }
        else
        {
            root->left = head;
            head->right = root;
            head = root;
        }

        solve(root->right, head);
    }
    Node *bToDLL(Node *root)
    {
        Node *head = NULL;
        Node *temp = head;

        solve(root, head);
        return head;
    }
};
