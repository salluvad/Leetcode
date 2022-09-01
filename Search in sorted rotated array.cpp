class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0 , r = nums.size()-1;
        int mid ;
        

        while(l<=r) {
           mid = (l+r)/2; 
            
            if (t == nums[mid]){
                return mid ;
            }
            //check if the left is sorted 
            if(nums[l]<=nums[mid]){
                if(t > nums[mid]){
                    l = mid+1;
                }
                else if(t<nums[l]){
                    l = mid+1;
                } else if(t<nums[mid]){
                    r = mid-1;
                }
                
            }
            //check if right is sorted 
            else {
                if(t < nums[mid]){
                    r = mid -1;
                }
                else if(t > nums[r]){
                    r = mid-1;
                }
                else if(t > nums[mid]){
                    l = mid+1;
                }
                
            }
        }
        return -1;


    }            
    
};
