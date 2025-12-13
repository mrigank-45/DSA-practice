#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Compare
    {
        bool operator()(const string &p1, const string &p2)
        {
            if (p1.length() == p2.length())
            {
                int i = 0;
                while(i<p1.length()){
                    if(p1[i] != p2[i]){
                        return p1[i] > p2[i];
                    }
                    i++;
                }
                return true;
            }
            return p1.length() > p2.length();
        }
    };
    string kthLargestNumber(vector<string> &nums, int k)
    {
        int n = nums.size();
        priority_queue<string,vector<string>,Compare> pq;

        for(int i =0; i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
