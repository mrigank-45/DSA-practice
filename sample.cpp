#include <bits/stdc++.h>
using namespace std;

// struct TreeNode
// {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

class Solution
{
public:
    map<int, int> vis;
    int checkBST(int root, long min, long max, int left, int n)
    {
        if (left == 0)
        {
            return 1;
        }

        if (root > min && root < max)
        {
            int ans = 1;

            for (int i = 1; i <= n; i++)
            {
                if (vis[i] == 0)
                {
                    vis[i] = 1;
                    int c1 = checkBST(i, min, root, left - 1 - 1, n);
                    int c2 = checkBST(i, root, max, left - 1, n);
                    vis[i] = 0;
                    ans += c1 + c2;
                }
            }
            return ans;
        }
        else
        {
            return 0;
        }
    }
    int numTrees(int n)
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 1;
            ans + checkBST(i, LONG_MIN, LONG_MAX, n, n);
            vis[i] = 0;
        }

        return ans;
    }
};
