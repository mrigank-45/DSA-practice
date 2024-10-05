#include <bits/stdc++.h>
using namespace std;

int allocateServers(vector<vector<int>> &matrix, vector<int> &serverCapacities, vector<int> &locationUsers)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int totalCost = 0;
    int serverId = 1, locationId = 1; 

    while (rows > 0 && cols > 0)
    {
        int minVal = min(serverCapacities[0], locationUsers[0]);

        cout << "Allocating " << minVal << " users from Server " << serverId << " to Location " << locationId << endl;

        totalCost += (matrix[0][0] * minVal);

        serverCapacities[0] -= minVal;
        locationUsers[0] -= minVal;

        if (serverCapacities[0] == 0)
        {
            serverCapacities.erase(serverCapacities.begin());
            matrix.erase(matrix.begin());
            rows--;
            serverId++; 
        }

        if (locationUsers[0] == 0)
        {
            for (int i = 0; i < rows; ++i)
            {
                matrix[i].erase(matrix[i].begin());
            }
            locationUsers.erase(locationUsers.begin());
            cols--;
            locationId++; 
        }
    }

    return totalCost;
}

int main()
{
    vector<vector<int>> matrix = {{10, 2, 20, 11},  {12, 7, 9, 20}, {4, 14, 16, 18}};
    vector<int> serverCapacities = {25, 25, 30}; 
    vector<int> locationUsers = {10, 25, 25, 20};    

    int result = allocateServers(matrix, serverCapacities, locationUsers);

    cout << "Total Cost for Allocation: " << result << endl;

    return 0;
}
