// Write a function to find the longest common prefix string amongst an array of strings.
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include <bits/stdc++.h>
using namespace std;

// from internet
void sort(string s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        string temp = s[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length())
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

int main()
{
    int n = 4;
    string arr[n] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    sort(arr, n);

    string f = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i].find(f) == 0) // found
        {
            continue;
        }
        else
        {
            while (arr[i].find(f) != 0) // till not found
            {
                if (f.size() == 0)
                {
                    return -1;
                }
                else
                {
                    f.pop_back();
                }
            }
        }
    }
    // return f;
    cout << f << endl;
}
