#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
public:
    vector<int> solve(Node *target, unordered_map<Node *, Node *> &parent, int k)
    {
        queue<Node *> q;
        q.push(target);
        unordered_map<Node *, bool> visited;
        visited[target] = true;
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (level == k)
            {
                vector<int> ans;
                while (!q.empty())
                {
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                return ans;
            }
            while (size--)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left])
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right])
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !visited[parent[curr]])
                {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            level++;
        }
        return {};
    }
    void parentMappingBFS(Node *root, int target, unordered_map<Node *, Node *> &parent, Node *&targetNode)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->data == target)
                {
                    targetNode = curr;
                }
                if (curr->left)
                {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        Node *targetNode = NULL;
        unordered_map<Node *, Node *> parent;

        parentMappingBFS(root, target, parent, targetNode);

        vector<int> ans = solve(targetNode, parent, k);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
