You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
  
  
  class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
      // to get the mini diff between highest and lowest K scores , 
      // we maintain sliding window of size K , so diff between left and right pointers is our diff , which needs to be 
    // miminized 
     
    //1. sort the arrray 
    sort(nums.begin(),nums.end());
    
    int res = INT_MAX ;
    int l = 0 ; 
    int r = k-1;
    
    while(r<nums.size()){
        res = min(res,nums[r]-nums[l]);
        l++;
        r++;
    }
        return res;
    }
};
