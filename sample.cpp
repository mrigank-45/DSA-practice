#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shiftRight(vector<int> v)
    {
        int n = v.size();
        vector<int> res(n);
        // shift right
        for (int i = 1; i < n; i++)
        {
            res[i] = v[i - 1];
        }
        res[0] = v[n - 1];
        return res;
    }
    vector<int> shiftLeft(vector<int> v)
    {
        int n = v.size();
        vector<int> res(n);
        // shift left
        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = v[i + 1];
        }
        res[n - 1] = v[0];
        return res;

    }
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> res = mat;

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j % 2 == 0)
                {
                    mat[j] = shiftLeft(mat[j]);
                }
                else
                {
                    mat[j] = shiftRight(mat[j]);
                }
            }
        }

        if (mat == res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
