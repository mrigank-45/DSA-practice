#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3] = {5, 1, 2};

    swap(arr[0], arr[1]);
    reverse(arr, arr + 3);
    next_permutation(arr, arr + 3);
    sort(arr, arr + 3);

    // for (int i = 0; i < 3; i++)
    // {
    //     if (arr[i] == 5)
    //     {
    //         continue;
    //         cout << "not breaking" << endl;
    //     }
    //     break;
    //     cout << "not breaking 2" << endl;
    // }

    return 0;
}
