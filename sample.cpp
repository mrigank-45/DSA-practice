#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *root1, Node *root2)
    {
        Node *temp = new Node(0);
        Node *res = temp;

        while (root1 != NULL && root2 != NULL)
        {
            if (root1->data < root2->data)
            {
                temp->bottom = root1;
                temp = temp->bottom;
                root1 = root1->bottom;
            }
            else
            {
                temp->bottom = root2;
                temp = temp->bottom;
                root2 = root2->bottom;
            }
        }

        if (root1 != NULL)
            temp->bottom = root1;
        else
            temp->bottom = root2;

        return res->bottom;
    }
    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == NULL)
            return root;

        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};
