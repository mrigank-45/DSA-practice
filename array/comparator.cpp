#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        // people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}
        sort(people.begin(), people.end(), comparator);

        // prints: {7,0}, {7,1}, {6,1}, {5,0}, {5,2}, {4,4}
        for(int i = 0; i < n; i++){
            cout << people[i][0] << " " << people[i][1] << endl;
        }
        return people;
    }
};
