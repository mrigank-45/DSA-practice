// Given the root of a binary tree, return the sum of every tree node's tilt.

// The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node 
// values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the 
// node does not have a right child.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
    int solve(TreeNode* node, int &ans){

        if(node==NULL){
            return 0;
        }
        int leftSum = solve(node->left, ans);
        int rightSum = solve(node->right, ans);
        ans+= abs(leftSum-rightSum);
        return leftSum + rightSum + node->val;
    }

    int findTilt(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        int k = solve(root, ans);
        return ans;
        
    }
};
