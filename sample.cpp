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
    int solve(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->left == NULL && node->right == NULL)
        {
            int temp = node->data;
            node->data = 0;
            return temp;
        }

        // calls
        int left = solve(node->left);
        int right = solve(node->right);

        int temp = node->data;
        node->data = left + right;
        return temp + left + right;
        
    }
    void toSumTree(Node *node)
    {
        int sum = solve(node);
    }
};
