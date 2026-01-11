#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i =0; i<n; i++){
            if(dist[i]%speed[i] == 0){
                dist[i] = dist[i]/speed[i];
            }
            else{
                dist[i] = (dist[i]/speed[i])+1;
            }
        }
        sort(dist.begin(),dist.end());
        for(int i =1; i<n; i++){
            if((dist[i]<=i)){
                return i;
            }
        }
        return n;
        
    }
};
