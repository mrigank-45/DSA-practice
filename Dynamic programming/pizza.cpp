// Pizza With 3n Slices (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(int index, int &endingIndex, vector<int> &slices, int slicesCount)
    {
        if (slicesCount == 0 || index > endingIndex)
            return 0;

        int include = slices[index] + solveUsingRecursion(index + 2, endingIndex, slices, slicesCount - 1);

        int exclude = solveUsingRecursion(index + 1, endingIndex, slices, slicesCount);

        return max(include, exclude);
    }

    int solveUsingMemo(int index, int &endingIndex, vector<int> &slices, int slicesCount, vector<vector<int>> &dp)
    {
        if (slicesCount == 0 || index > endingIndex)
            return 0;

        if (dp[index][slicesCount] != -1)
            return dp[index][slicesCount];

        int include = slices[index] + solveUsingMemo(index + 2, endingIndex, slices, slicesCount - 1, dp);

        int exclude = solveUsingMemo(index + 1, endingIndex, slices, slicesCount, dp);

        return dp[index][slicesCount] = max(include, exclude);
    }

    int solveUsingTabu(vector<int> &slices, int startIndex, int endIndex)
    {
        int n = slices.size();
        vector<vector<int>> dp(n + 2, vector<int>((n / 3) + 2, 0));
        // base case already done

        for (int index = endIndex; index >= startIndex; index--)
        {
            for (int sliceCount = 1; sliceCount <= n / 3; sliceCount++)
            {
                int include = slices[index] + dp[index + 2][sliceCount - 1];

                int exclude = dp[index + 1][sliceCount];

                dp[index][sliceCount] = max(include, exclude);
            }
        }

        return startIndex == 0 ? dp[0][n / 3] : dp[1][n / 3];
    }

    int solveUsingTabuSO(vector<int> &slices, int startIndex, int endIndex)
    {
        int n = slices.size();
        vector<int> previous1(n / 3 + 1, 0);
        vector<int> previous2(n / 3 + 1, 0);
        vector<int> current(n / 3 + 1, 0);
       
        // index + 1 -> previous1
        // index + 2 - > previous2
        // index -> current
        for (int index = endIndex; index >= startIndex; index--)
        {
            for (int sliceCount = 1; sliceCount <= n / 3; sliceCount++)
            {
                int include = slices[index] + previous2[sliceCount - 1];

                int exclude = previous1[sliceCount];

                current[sliceCount] = max(include, exclude);
            }
            previous2 = previous1;
            previous1 = current;
        }

        return current[n / 3];
    }

    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int end1 = n - 2;
        int end2 = n - 1;

        // recursive solution
        // int choice1 = solveUsingRecursion(0,end1, slices, n / 3);
        // int choice2 = solveUsingRecursion(1,end2, slices, n / 3);
        // return max(choice1, choice2);

        // memorization solution
        // vector<vector<int> >dp1(n, vector<int>(n/3 + 1, -1));
        // vector<vector<int> >dp2(n, vector<int>(n/3 + 1, -1));
        // int choice1 = solveUsingMemo(0,end1, slices, n / 3,dp1);
        // int choice2 = solveUsingMemo(1,end2, slices, n / 3,dp2);
        // return max(choice1, choice2);

        // tabulation solution
        // int choice1 = solveUsingTabu(slices,0,end1);
        // int choice2 = solveUsingTabu(slices,1,end2);
        // return max(choice1, choice2);

        // space optimization
        int choice1 = solveUsingTabuSO(slices, 0, end1);
        int choice2 = solveUsingTabuSO(slices, 1, end2);
        return max(choice1, choice2);
    }
};
