class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // kadane's algo
        if(nums.size()==0){
            return 0;
        }
        // we keep track of max and min products so far 
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int res = max_so_far;
        
        for(int i = 1 ; i<nums.size();i++){
            int curr = nums[i];
            
           int temp_max= max(curr,max(max_so_far*curr,min_so_far*curr));
            
           int temp_min= min(curr,min(max_so_far*curr,min_so_far*curr));
           
            max_so_far= temp_max;
            min_so_far = temp_min;
            
            res = max(res,max_so_far);
        }
        return res;
        
    }
};
