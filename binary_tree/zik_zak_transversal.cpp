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
    vector<vector<int>> zigzagLevelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        queue<Node *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {

            int size = q.size();
            vector<int> ans(size);

            // Level Process
            for (int i = 0; i < size; i++)
            {

                Node *frontNode = q.front();
                q.pop();

                // normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // direction change 
            leftToRight = !leftToRight;

            result.push_back(ans);
        }

        return result;
    }
};
