class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;  // front index
        for(int j = 0 ; j<nums.size();j++){  // j is running index
          
            if(nums[i]==0 and nums[j]!=0){
                swap(nums[i],nums[j]);
            }
            if(nums[i]!=0){
                i++;
            }
        }
        
    }
};
