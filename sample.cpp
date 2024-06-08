#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
    void solve(Node *root, unordered_map<int, vector<Node *>> &mp, int level)
    {
        if (root == NULL)
        {
            return;
        }

        mp[level].push_back(root);

        solve(root->left, mp, level + 1);
        solve(root->right, mp, level + 1);

        return;
    }
    Node *connect(Node *root)
    {
        unordered_map<int, vector<Node *>> mp;
        solve(root, mp, 0);

        for (auto it : mp)
        {
            vector<Node *> v = it.second;
            for (int i = 0; i < v.size() - 1; i++)
            {
                v[i]->next = v[i + 1];
            }
            v[v.size() - 1]->next = NULL;
        }

        return root;
    }
};
