// Find the Maximum Sum of Node Values
// For approach only: leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/5177822/o-n-greedy-very-easy-to-understand/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<long long>> temp(n, vector<long long>(2, -1)); // temp[current_index(node)][is_even]

        return calculateMax(nums, n, k, 0, 1, temp);
    }

private:
    long long calculateMax(vector<int> &nums, int n, int k, int curInd, int isEven, vector<vector<long long>> &temp)
    {
        if (curInd == n)
        { 
            return isEven == 1 ? 0 : LLONG_MIN;
        }
        if (temp[curInd][isEven] != -1)
        { 
            return temp[curInd][isEven];
        }

        // checking all possible variants (no XOR or XOR)
        long long noXor = nums[curInd] + calculateMax(nums, n, k, curInd + 1, isEven, temp);          // we don't change the number of XOR nodes
        long long withXor = (nums[curInd] ^ k) + calculateMax(nums, n, k, curInd + 1, !isEven, temp); // we added 1 XORed node

        long long mxPossible = max(noXor, withXor);
        return  temp[curInd][isEven] = mxPossible;
    }
};
