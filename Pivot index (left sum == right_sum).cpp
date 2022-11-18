class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //prefix sum based 
        //find left sum and right sum for a given index
        int total = 0 ;
        for(auto i:nums){
            total+=i;
        }
        int left_sum = 0;
         int right_sum = 0;
        
        for(int i = 0; i<nums.size();i++){
            right_sum = total-nums[i]-left_sum;
            if(left_sum == right_sum){
                return i;
            }
            left_sum+=nums[i];
        }
        
        return -1;
    }
};
