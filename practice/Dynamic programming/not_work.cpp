#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    int solve(vector<int> nums, int i, int j, vector<vector<int>> &dp)
    {
        if (is_sorted(nums.begin(), nums.end()))
        {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;

            for(int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }

            cout << endl;

            return j;
        }

        if (i == nums.size())
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        vector<int> temp1 = nums;
        vector<int> temp2 = nums;


        // 3 Cases
        if (nums[i] == 1)
        {
            a = solve(nums, i + 1, j, dp);

            temp1[i] = 2;
            b = solve(temp1, i + 1, j + 1, dp);

            temp2[i] = 3;
            c = solve(temp2, i + 1, j + 1, dp);
        }
        if (nums[i] == 2)
        {
            temp1[i] = 1;
            a = solve(temp1, i + 1, j + 1, dp);

            b = solve(nums, i + 1, j, dp);

            temp2[i] = 3;
            c = solve(temp2, i + 1, j + 1, dp);
        }
        if (nums[i] == 3)
        {
            temp1[i] = 1;
            a = solve(temp1, i + 1, j + 1, dp);

            temp2[i] = 2;
            b = solve(temp2, i + 1, j + 1, dp);

            c = solve(nums, i + 1, j, dp);
        }

        dp[i][j] = min(a, min(b, c));

        return min(a, min(b, c));
    }

    int minimumOperations(vector<int> &nums)
    {
        if (is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(nums, 0, 0, dp);
    }
};
