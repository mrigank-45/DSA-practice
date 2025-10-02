#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> next(n, -1);
        int flag = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            next[i] = flag;
            if (dominoes[i] != '.')
            {
                flag = i;
            }
        }
        int i = 0, curr = 0;
        while (i < n)
        {
            if (dominoes[i] == 'R')
            {
                if (next[i] == -1)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        dominoes[j] = 'R';
                    }
                    break;
                }
                else if (dominoes[next[i]] == 'L')
                {
                    int j = i + 1;
                    int k = next[i] - 1;
                    while (j < k)
                    {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                        j++;
                        k--;
                    }
                    i = next[i] + 1;
                }
                else
                {
                    for (int j = i + 1; j < next[i]; j++)
                    {
                        dominoes[j] = 'R';
                    }
                    i = next[i];
                }
            }
            else
            {
                i++;
            }
        }

        vector<int> prev(n, -1);
        flag = -1;
        for (int i = 0; i < n; i++)
        {
            prev[i] = flag;
            if (dominoes[i] != '.')
            {
                flag = i;
            }
        }

        i = n - 1;
        while (i >= 0)
        {
            if (dominoes[i] == 'L')
            {
                if (prev[i] == -1)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        dominoes[j] = 'L';
                    }
                    break;
                }
                else if (dominoes[prev[i]] == 'R')
                {
                    int j = prev[i] + 1;
                    int k = i - 1;
                    while (j < k)
                    {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                        j++;
                        k--;
                    }
                    i = prev[i] - 1;
                }
                else
                {
                    for (int j = i - 1; j > prev[i]; j--)
                    {
                        dominoes[j] = 'L';
                    }
                    i = prev[i];
                }
            }
            else
            {
                i--;
            }
        }

        return dominoes;
    }
};
