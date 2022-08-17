//Neetcode
//use set to copy elements from array 
//find the start of sequence and try to maximize that sequence

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
