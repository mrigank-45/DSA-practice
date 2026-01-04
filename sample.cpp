#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> rem1, rem2;
        for(int i =0; i<n;i++){
            sum += nums[i];
            if(nums[i]%3 == 1){
                rem1.push_back(nums[i]);
            }
            if(nums[i]%3 == 2){
                rem2.push_back(nums[i]);
            }
        }
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if(sum%3 == 0){
            return sum;
        }
        else if(sum%3 == 1){
            int op1 = INT_MIN, op2 = INT_MIN;
            if(rem1.size()>=1){
                op1 = sum - rem1[0];
            }
            if(rem2.size()>=2){
                op2 = sum - rem2[0] - rem2[1];
            }
            return max(op1, op2);
        }
        else{
            int op1 = INT_MIN, op2 = INT_MIN;
            if(rem2.size()>=1){
                op1 = sum - rem2[0];
            }
            if(rem1.size()>=2){
                op2 = sum - rem1[0] - rem1[1];
            }
            return max(op1, op2);
        }
    }
};
