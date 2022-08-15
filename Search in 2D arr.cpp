class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //convert 2d array to a virtual 1D array
        // indexs of row , col are curr index/n and curr index%n respectively
        
        int m = matrix.size();
        if(m ==0){
            return false;
        }
        int n = matrix[0].size();
        
        int left = 0 , right = m*n-1;
        
        int mid,mid_ele;
        
        while(left<=right){
            mid = (left+right)/2;
            mid_ele = matrix[mid/n][mid%n];
            if(target== mid_ele){
                return true;
            } else {
                if(target < mid_ele) {
                    right = mid-1;
                } else left = mid+1;
                
                }
            
            }
           return false;
        }
        
    
};
