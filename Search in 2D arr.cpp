/*
The algorithm is a standard binary search :

Initialise left and right indexes left = 0 and right = m x n - 1.

While left <= right :

Pick up the index in the middle of the virtual array as a pivot index : pivot_idx = (left + right) / 2.

The index corresponds to row = pivot_idx // n and col = pivot_idx % n in the initial matrix, and hence one could get the pivot_element. This element splits the virtual array in two parts.

Compare pivot_element and target to identify in which part one has to look for target.

*/


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
