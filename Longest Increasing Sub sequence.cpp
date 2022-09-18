class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP
        if(nums.size()==0) return 0;
        
        int n= nums.size();
        int LIS[n];
        
        LIS[0] = 1;
        
        for(int i = 1; i<n;i++){
                LIS[i]=1;
            for(int j = 0 ; j<i;j++){   
                if(nums[i]>nums[j] and LIS[i]<LIS[j]+1){
                    LIS[i]=LIS[j]+1;
                }
                
            }
           
        }
        return *max_element(LIS, LIS+n); 
        
    }
};
