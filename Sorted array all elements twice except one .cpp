/// o(n) solution is to use xor of all elements 


/// this is o(logn) sol:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // we use binary search to find the single element 
        // one observation is in the left half , first instance of a number starts at even index
        // and in right first instance starts at odd index 
        // eg 1,1,2,3,3,4,4,5,5,   before two is left half and after 2 is right half 
        
        int low =0;
        int high = nums.size()-2;   // this is beaucse if single element is last index , our left pointer will never reach it if we keep high at n-1, eg 1,1,2,2,3,3,4
        
        while(low<=high){
            int mid = (low+high) >>1;
            
            //check if it lies in left or right half 
            if(mid%2 ==0){    // even index index
                if(nums[mid]==nums[mid+1]){
                    //shrink the left half
                    low = mid+1 ;
                } else high = mid-1;
            } else {
                if(nums[mid]==nums[mid+1]){
                    //shrink the left half
                    high = mid-1;
                } else low = mid+1;
            }
        }
        
        return nums[low];
    }
};
