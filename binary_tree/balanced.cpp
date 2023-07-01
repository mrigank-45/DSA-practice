
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
private:
    int height(struct Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }

public:
    bool isBalanced(Node *root)
    {
        if (root ==NULL)
        {
            return true;
        }

        bool c1 = isBalanced(root->left);
        bool c2 = isBalanced(root->right);
        bool c3 = abs(height(root->left) - height(root->right)) <= 1;

        if(c1 && c2 && c3){
            return true;
        }
        else{
            return false;
        }
    }

    //********* Optmised Approach in O(n)
    pair<bool, int> isBalancedFast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<int, int> left = isBalancedFast(root->left);
        pair<int, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (leftAns && rightAns && diff)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    //********
};
