// Minimum sideways jumps (leetcode)

#include <bits/stdc++.h>
using namespace std;

// recursion
int solve(int currPos, int currLane, vector<int> &obstacles)
{
    if (currPos == obstacles.size() - 1)
        return 0;

    // check if you can go straight
    if (obstacles[currPos + 1] != currLane)
        return solve(currPos + 1, currLane, obstacles);

    int ans = INT_MAX;
    for (int i = 1; i <= 3; i++)
    {
        if (i != currLane && obstacles[currPos] != i)
        {
            ans = min(ans, 1 + solve(currPos + 1, i, obstacles));
        }
    }
    return ans;
}

// recursion + meororisation
int solve1(int currPos, int currLane, vector<int> &obstacles, vector<vector<int>> &dp)
{
    if (currPos == obstacles.size() - 1)
        return 0;

    if (dp[currPos][currLane] != -1)
        return dp[currPos][currLane];

    // check if you can go straight
    if (obstacles[currPos + 1] != currLane)
        return solve1(currPos + 1, currLane, obstacles, dp);

    int ans = INT_MAX;
    for (int i = 1; i <= 3; i++)
    {
        if (i != currLane && obstacles[currPos] != i)
        {
            ans = min(ans, 1 + solve1(currPos + 1, i, obstacles, dp));
        }
    }
    return dp[currPos][currLane] = ans;
}

// tabulation
int solve2(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    // [position,lane]
    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));

    for (int i = 0; i <= 3; i++)
        dp[n][i] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[currPos + 1] != currLane + 1)
            {
                dp[currPos][currLane] = dp[currPos + 1][currLane];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    if (i != currLane && obstacles[currPos] != i + 1)
                    {
                        // doing currPos + 1 since we are coming from back in tabulation
                        ans = min(ans, 1 + dp[currPos + 1][i]);  
                    }
                }
                dp[currPos][currLane] = ans;
            }
        }
    }
    return min(dp[0][2], min(dp[0][3] + 1, dp[0][1] + 1));
}

// space optamization
int solve3(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<int> curr(3, INT_MAX);
    vector<int> prev(3, 0);
    for (int currPos = n - 2; currPos >= 0; currPos--)
    {
        for (int currLane = 0; currLane <= 2; currLane++)
        {
            if (obstacles[currPos + 1] != currLane + 1)
                curr[currLane] = prev[currLane];
            else
            {
                int ans = INT_MAX;
                for (int i = 0; i <= 2; i++)
                {
                    if (i != currLane && obstacles[currPos] != i + 1)
                    {
                        ans = min(ans, 1 + prev[i]);
                    }
                }
                curr[currLane] = ans;
            }
        }
        prev = curr;
    }
    return min(prev[2], min(prev[1] + 1, prev[3] + 1));
}

int minSideJumps(vector<int> &obstacles)
{
    return solve(0, 2, obstacles);

    int n = obstacles.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve1(0, 2, obstacles, dp);

    return solve2(obstacles);

    return solve3(obstacles);
}
