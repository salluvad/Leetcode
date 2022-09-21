Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
  
  
  ///////////
  
  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int longest = 1;
        if(nums.size()==0){
            return 0;
           }
        
        if(nums.size() == 1) return 1;
        
        for(auto n:nums){
            //if it is start of seq , i.e it has no left neighbor on an infinity line
           if (s.find(n-1)==s.end()){
               int len = 0;
               while(s.find(n+len)!=s.end()){
                   len++;   
               }
               longest = max(longest,len);
           }
               
           }
        return longest;
    }
};
