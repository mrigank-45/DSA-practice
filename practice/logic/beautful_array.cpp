// find-the-minimum-possible-sum-of-a-beautiful-array

// The idea is to exclude the numbers (target/2,target) from the sequence 1,2,3,4 ..... as it will lead to the pairs whose sum will be equal to target.

// Eg:
// n = 7 target = 9
// Sequence = 1,2,3,4,5,6,7,8,9,10,11 .....
// excluding (4,9)
// So arr = 1,2,3,4,9,10,11
// sum = 40

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Sum of AP when first and last terms are known.
    long long getSum(long long n,long long a,long long l) {
        long long sum;
        if(n%2==0){
            sum = (n/2)*(a+l);
        }else{
            sum = ((a+l)/2)*n;
        }
        return sum;
    }

    long long minimumPossibleSum(int n, int target) {

        int a = (target/2);
        int l = target;

        if(a>n) {
            return getSum(n,1,n);
        }
                
        return getSum(a,1,a) + getSum(n-a,l,l+n-a-1);
    }
};
