// construct tree from preorder and inorder transversal or from postorder and inorder transversal.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionForPreorder
{
public:
    int findpos(vector<int> &inorder, int &ele, int &size)
    {
        for (int i = 0; i < size; i++)
        {
            if (inorder[i] == ele)
                return i;
        }
        return -1;
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &size, int &preindex, int inorderstart, int inorderend)
    {
        if ((preindex >= size) || (inorderstart > inorderend))
            return NULL;

        int ele = preorder[preindex++];
        TreeNode *root = new TreeNode(ele);
        int pos = findpos(inorder, ele, size);
        root->left = solve(preorder, inorder, size, preindex, inorderstart, pos - 1);
        root->right = solve(preorder, inorder, size, preindex, pos + 1, inorderend);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int size = preorder.size();
        int preindex = 0, inorderstart = 0, inorderend = size - 1;
        return solve(preorder, inorder, size, preindex, inorderstart, inorderend);
    }
};

class SolutionForPostorder
{
public:
    int findpos(vector<int> &inorder, int ele, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == ele)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, int n)
    {
        if (index < 0 || start > end)
            return nullptr;
        int ele = postorder[index--];
        int pos = findpos(inorder, ele, n);

        TreeNode *temp = new TreeNode(ele);
        temp->right = solve(inorder, postorder, index, pos + 1, end, n);

        temp->left = solve(inorder, postorder, index, start, pos - 1, n);

        return temp;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = postorder.size();
        int index = n - 1;
        TreeNode *ans = solve(inorder, postorder, index, 0, n - 1, n);
        return ans;
    }
};
