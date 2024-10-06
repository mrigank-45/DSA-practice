#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        int n = enemyEnergies.size();
        sort(enemyEnergies.begin(), enemyEnergies.end());
        reverse(enemyEnergies.begin(), enemyEnergies.end());

        if (currentEnergy < enemyEnergies[n - 1])
        {
            return 0;
        }

        int i = 0;
        long long ans = 0;

        while (i < n)
        {
            // get all the poinst from last enemy
            ans += currentEnergy/enemyEnergies[n-1];
            currentEnergy = currentEnergy % enemyEnergies[n-1];
            

            // get energy from the current enemy
            while (currentEnergy < enemyEnergies[n - 1])
            {
                currentEnergy += enemyEnergies[i];
                i++;
                if(i == n)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
