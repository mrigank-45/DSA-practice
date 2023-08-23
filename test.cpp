#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &price, int ind, int N, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTaken = 0 + solve(price, ind - 1, N, dp);

    int taken = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        taken = price[ind] + solve(price, ind, N - rodLength, dp);

    return dp[ind][N] = max(notTaken, taken);
}

int tabulation(vector<int> &price, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j * price[i];
            }
            else
            {
                int notTaken = dp[i - 1][j];
                int taken = INT_MIN;
                int rodLength = i + 1;
                if (rodLength <= j)
                    taken = price[i] + dp[i][j - rodLength];

                dp[i][j] = max(notTaken, taken);
            }
        }
    }

    return dp[N - 1][N];
}

int cutRod(vector<int> &price, int N)
{

    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    return solve(price, N - 1, N, dp);
}

int main()
{

    vector<int> price = {2, 5, 7, 8, 10};

    int n = price.size();

    cout << "The Maximum price generated is " << cutRod(price, n);
}
