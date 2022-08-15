/*
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // three pointer technique from the end as we know we have empty spaces from end
        int p1 = m-1;
        int p2= n-1;
        int p3 = m+n-1;
        while(p1>=00 and p2>=00){    // while elemenst in both arrays 
         
            if(nums1[p1]>=nums2[p2]){
                nums1[p3] = nums1[p1];
                p1--;
            } else {
                nums1[p3] = nums2[p2];
                p2--;
            }
            p3--;
        }
        // if any elements left in nus2
        while(p2>=0){
            nums1[p3] = nums2[p2];
            p3--;
            p2--;
        }
        
    }
};
