class Solution {
public:
    int findMin(vector<int>& nums) {
        //pivot point , left half is greater than pivot point and right half is also greter than pivot
        // eg: 3 4 5 1 2
        if(nums.size()==1){
            return nums[0];
        }
        int low = 0 ;
        int high = nums.size()-1;
        
        
        // check if array is rotated or not 
        if(nums[low]<nums[high]) {
            return nums[0];
        }
        
        while(low<=high){
            int mid = (low+high) >>1;
            
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            
            //move low and high points
            if(nums[mid]>nums[0]){
                //min is on the right
                low = mid+1;
            } else high = mid-1;
        }
        
        //if its not present
        return INT_MAX;
    }
};
