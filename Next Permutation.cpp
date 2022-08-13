/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory

*/
//https://www.youtube.com/watch?v=6qXO72FkqwM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size(); 
        
        if(n==1)
            return;
        
        int i=1;
        int lastInc = -1;  //. ?? index to the last peak 
        
        while(i<n) {    //Find the peak of last ASC order
            if(nums[i]>nums[i-1])
                lastInc = i;
            i+=1;
        }
        //if array in DSC order , convert to asc and return 
        //special case to handle 
        if(lastInc==-1) {   //Check if array is DSC
            for(i=0;i<n/2;++i)
                swap(nums[i],nums[n-i-1]);    // we can do sort ,but sort takes O(nlogn) , swap indexes takes O(n)
            return;
        }
        // Find the right most peak and swap it with previous value
        // special case is if there exists a smaller number to the right of the peak , we can 
        // swap prev elemnt to lastInc and the next  greater element in the  remaing array after LastInc
        //Find element in the range (nums[lastInc-1] to nums[lastInc]) to the right
        int mn = nums[lastInc];
        int index = lastInc;
        for(i=lastInc;i<n;++i) {
            if(nums[i]>nums[lastInc-1] and nums[i]<nums[index]) {
                index = i;
            }
        }
        swap(nums[lastInc-1],nums[index]);
        sort(nums.begin()+lastInc,nums.end());
    }

        
    
};
