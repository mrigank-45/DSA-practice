#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};

    vector<int> ans;

    sort(v.begin(), v.end());

    int m = min(v[0],v[1]);
    cout<<m<<endl;


    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
}
