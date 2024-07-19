#include <bits/stdc++.h>
using namespace std;

int maxDisplacement(string commands, int N)
{
    int n = commands.size();
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, -1));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        char command = commands[i - 1];
        for (int j = 0; j <= N; ++j)
        {
            if (dp[i - 1][j] != -1)
            {
                if (command == 'F')
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
                }
                if (j < N)
                {
                    if (command == 'F')
                    {
                        dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] - 1);
                    }
                    else
                    {
                        dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + 1);
                    }
                }
            }
        }
    }

    int maxDisplacement = 0;
    for (int j = 0; j <= N; ++j)
    {
        maxDisplacement = max(maxDisplacement, abs(dp[n][j]));
    }

    return maxDisplacement;
}

int main()
{
    string commands;
    int N;

    cin >> commands >> N;

    cout << maxDisplacement(commands, N) << endl;

    return 0;
}
