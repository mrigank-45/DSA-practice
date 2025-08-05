#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int solve(int id, unordered_map<int, pair<int, vector<int>>> &mp)
    {
        int totalImportance = mp[id].first;
        for (int subId : mp[id].second)
        {
            totalImportance += solve(subId, mp);
        }
        return totalImportance;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, pair<int, vector<int>>> mp;
        for (auto emp : employees)
        {
            mp[emp->id] = {emp->importance, emp->subordinates};
        }
        return solve(id, mp);
    }
};
