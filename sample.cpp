#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        queue<Node *> q;
        q.push(root);
        Node *prev;

        while (!q.empty())
        {
            int N = q.size();
            prev = NULL;
            while (N--)
            {
                Node *curr = q.front();
                q.pop();

                if (prev)
                    prev->next = curr;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                prev = curr;
            }
        }
        return root;
    }
};
