#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode *root = new TreeNode(nums[maxIndex]);

        vector<int> leftSubtree(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightSubtree(nums.begin() + maxIndex + 1, nums.end());

        root->left = constructMaximumBinaryTree(leftSubtree);
        root->right = constructMaximumBinaryTree(rightSubtree);

        return root;
    }
};
