// lower_bound and upper_bound in vector
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Note that the array is sorted
    int gfg[] = { 5, 6, 6, 6, 8 };
 
    vector<int> v(gfg, gfg + 8); // 5 5 5 6 6 6 7 7
 
    int lower = *lower_bound(v.begin(), v.end(), 7); // gives iterator to element equal to or greater than val, else gives v.end()
    int upper = *upper_bound(v.begin(), v.end(), 10); // gives iterator to element greater than val, else gives v.end()

    int cnt = v.end() - upper_bound(v.begin(), v.end(), 6); // gives count of elements greater than val
 
    cout << "lower_bound for 6 is "
         << (lower) << '\n';
    cout << "upper_bound for 6 is "
         << (upper) << '\n';
 
    return 0;
}
