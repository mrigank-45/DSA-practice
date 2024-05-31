// find the longest palindromic substring
// Input: S = "aaaabbaa"  Output: aabbaa
// A O(n^2) time and O(1) space program

#include <bits/stdc++.h>
using namespace std;

// This function prints the longest palindrome substring
int longestPalSubstr(string str)
{
    int n = str.size(); // calculating size of string
    if (n < 2)
    {
        return n;
    }

    int maxLength = 1, start = 0;
    int low, high;

    for (int i = 0; i < n; i++)
    {
        low = i - 1;
        high = i + 1;
        while (high < n && str[high] == str[i]) // check equals in right direction
        {
            high++;
        }

        while (low >= 0 && str[low] == str[i]) // check equals in left direction
        {
            low--;
        }

        while (low >= 0 && high < n && str[low] == str[high]) // till equal in both side
        {
            low--;
            high++;
        }

        int length = high - low - 1;

        if (maxLength < length)
        {
            maxLength = length;
            start = low + 1;
        }
    }

    cout << "Longest palindrome substring is: ";
    cout << str.substr(start, maxLength);

    return maxLength;
}

// Driver program to test above functions
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalSubstr(str)
         << endl;
    return 0;
}
