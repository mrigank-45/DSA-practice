#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string add_strings(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        int i = n1 - 1, j = n2 - 1, carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
            {
                sum += s1[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += s2[j] - '0';
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            res += to_string(sum);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    string solve(int arr[], int n)
    {
        sort(arr, arr + n);

        string s1 = "", s2 = "";
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s1 += to_string(arr[i]);
            }
            else
            {
                s2 += to_string(arr[i]);
            }
        }

        string res = add_strings(s1, s2);

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != '0')
            {
                return res.substr(i);
            }
        }

        return "0";
    }
};
