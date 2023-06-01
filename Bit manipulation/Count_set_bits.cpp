// Input : n = 6
// Output : 2
// Binary representation of 6 is 110 and has 2 set bits

// Input : n = 13
// Output : 3
// Binary representation of 13 is 1101 and has 3 set bits

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin>>n;

    int count = 0;
    while (n) {
        //checking if the last bit is 1
        if (n & 1)
        {
            count++;
        }

        n = n>>1;  // right shift the number
    }
    cout<<count<<endl;


    return 0;
}
