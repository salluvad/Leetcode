


Given an integer array nums and an integer val, 
remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
  
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        /*
        When nums[j]nums[j] equals to the given value, skip this element by incrementing jj. As long as nums[j] \neq        valnums[j] =val, we copy nums[j]nums[j] to nums[i]nums[i] and increment both indexes at the same time. 
        Repeat the process until jj reaches the end of the array and the new length is ii.
      */
       /* int idx = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[idx++] = nums[i]; 
            }
        }
        return idx;
        */
    // there is other optimized approach
   // since order of elements odesn't matter , when num[i] == val , replace it with last element and discard the last one 
        int i = 0 ;
        int n = nums.size();
        while(i<n){
            if(nums[i]==val){
                nums[i]=nums[n-1];
                n--;
            } else {
                i++;
            }
        }
        
        return n;
    }
};
