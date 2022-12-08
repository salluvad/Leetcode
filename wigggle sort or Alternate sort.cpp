//Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*brute force  is to just sort the array first, then swap elements pair-wise starting from the second element. For example:

   [1, 2, 3, 4, 5, 6]
       ↑  ↑  ↑  ↑
      swap  swap

=> [1, 3, 2, 5, 4, 6]
           
 */   //one pass sol, maintain a flag to find if its less or greater 
    bool less = true;
    for(int i = 0 ; i < nums.size()-1;i++){
        if(less){
            if(nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }else {
             if(nums[i]<nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
        less = !less;
    }
           
    }
};
