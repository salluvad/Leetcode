/////////////////////////////////////////////
The below both solutions work 


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        int mid ;
        while (low <= high) { //<--- step 2
        int mid = (low + high) >> 1; //<----step 3
        if (nums[mid] == target)
          return mid; // <---step 4

        if (nums[low] <= nums[mid]) { //<---step 5
          if (nums[low] <= target && nums[mid] >= target)
            high = mid - 1; //<---step 6 
          else
            low = mid + 1; //<---step 7
          } else { //<---step 7
          if (nums[mid] <= target && target <= nums[high])
            low = mid + 1;
          else
            high = mid - 1;
          }
      }  

      
        return -1;


    }     
     
    
        
    
};




///////////////////////////////////////////////////
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
