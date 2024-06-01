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
    map<Node *, Node *> parent_map;
    int ans = INT_MAX;
    void makeParent(Node *root, Node *parent)
    {
        if (root == NULL)
            return;
        parent_map[root] = parent;
        makeParent(root->left, root);
        makeParent(root->right, root);
    }
    Node *find_node(Node *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == val)
        {
            return root;
        }
        if (find_node(root->left, val) != NULL)
        {
            return find_node(root->left, val);
        }

        return find_node(root->right, val);
    }
    void dfs(Node *root, int b, int dis, Node *prev)
    {
        if (root == NULL)
            return;
        if (root->data == b)
        {
            ans = min(ans, dis);
            return;
        }

        if (root->left != prev)
            dfs(root->left, b, dis + 1, root);
        if (root->right != prev)
            dfs(root->right, b, dis + 1, root);
        if (parent_map[root] != prev)
            dfs(parent_map[root], b, dis + 1, root);
    }
    int findDist(Node *root, int a, int b)
    {
        makeParent(root, NULL);

        Node *target = find_node(root, a);
        dfs(target, b, 0, NULL);

        return ans;
    }
};
