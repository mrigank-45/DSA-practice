#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string s1, string s2)
    {

        long long int n1 = stoll(s1);
        long long int n2 = stoll(s2);

        long long int n = n1 * n2;
        return to_string(n);
    }
};
