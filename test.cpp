// lower_bound and upper_bound in vector
 
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector
 
using namespace std;
 
int main()
{
    // Note that the array is sorted
    int gfg[] = { 5, 6, 6, 6, 8 };
 
    vector<int> v(gfg, gfg + 8); 
 
    int lower = *lower_bound(v.begin(), v.end(), 7);
    int upper = *upper_bound(v.begin(), v.end(), 10);
 
    cout << "lower_bound for 6 is "
         << (lower) << '\n';
    cout << "upper_bound for 6 is "
         << (upper) << '\n';
 
    return 0;
}
