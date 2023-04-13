#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    vector<long long int> v1;
    vector<long long int> v2;

    while (n>0)
    {
        v1.push_back(n%10);
        n=n/10;

    }
    int k =0;
    for (long long int i = 0; i < v1.size()/2; i++)
    {
        if (v1[i] != v1[v1.size()-i-1])
        {
            k++;
            break;
        }
        
    }
    if (k==1)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    
    
    
    

    return 0;
}
