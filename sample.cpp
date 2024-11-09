#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int pivotIndex(vector<int>& nums){
        int s =0 ;
        int e = nums.size() -1; 

        int mid = s + (e-s)/2; 

        while(s<e){
            if(nums[mid]>=nums[0]){
                s = mid + 1; 
            }
            else {
                e = mid; 
            }
            mid = s + (e-s)/2; 
        }
        return s; 
    }

    int binarySearch(vector <int>& nums, int s, int e, int ele){
        int beg = s; 
        int end = e; 

        int mid = beg + (end-beg)/2; 

        while(beg<=end){
            if(nums[mid]==ele){
                return mid; 
            }
            else if(nums[mid]<ele){
                  beg = mid + 1; 
            }
            else{
                end = mid -1;
            }
            mid = beg + (end-beg)/2; 
        }
        return -1; 
    }
    int search(vector<int>& nums, int target) {
        int pivot = pivotIndex(nums); 

        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
           return binarySearch(nums, pivot, nums.size()-1, target); 
        }
        else{
            return binarySearch(nums, 0, pivot - 1, target); 
        }      
    }
};
