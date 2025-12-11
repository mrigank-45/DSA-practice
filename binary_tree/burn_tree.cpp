// Minimum time to burn a tree (gfg)

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
    Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        Node *res = NULL;
        nodeToParent[root] = NULL;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front->data == target)
            {
                res = front;
            }
            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
    {
        map<Node *, bool> visited;
        visited[root] = true;

        queue<Node *> q;
        q.push(root);

        int time = 0;
        
        while (!q.empty())
        {
            bool flag = 0;               
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                // process neighbouring nodes
                Node *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if (flag == 1)
            {
                time++;
            }
        }
        return time;
    }
    int minTime(Node *root, int target)
    {
        // Algo
        // 1 = create node to parent mapping
        // 2 = find target node
        // 3 = burn the tree
        int time = 0;
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, target, nodeToParent);
        time = burnTree(targetNode, nodeToParent);
        return time;
    }
};
