// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k
// from the target node.
// You can return the answer in any order.

// *ALGO*
// First make a node to parent mapping, then start doing level order transversal from the target node k times and maintain a visited map so you do not go 
// to same node again, after k times, return the elements in the queue.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left)
            {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right)
            {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track; // node -> parent
        markParents(root, parent_track, target);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!queue.empty())
        { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left])
                {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]])
                {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while (!queue.empty())
        {
            TreeNode *current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};
