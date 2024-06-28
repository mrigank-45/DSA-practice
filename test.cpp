#include <bits/stdc++.h>
using namespace std;

int main()
{
    string arr[] = {"flower","flow","flight"};

    sort(arr, arr + 3); 

    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }



    return 0;
}
