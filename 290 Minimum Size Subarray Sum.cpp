Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target.
  If there is no such subarray, return 0 instead.
  
  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window tech , neetcode 
        int min_len = INT_MAX;
        int l = 0,r=0;
        int n = nums.size();
        int total = 0;
        
        for(;r<n;){
            
               total+=nums[r];
               while(total>=target) {
                   min_len = min(min_len,r-l+1);
                   total-=nums[l];
                   l++;
               }
               r++;
            }
            
            
         return (min_len!= INT_MAX) ? min_len : 0;
    
    }
};
