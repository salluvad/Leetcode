/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j]
*/



class Solution {
public:
    void merge(vector<int> &nums, int si, int ei, int mid, int &count){
        int j = mid;
        int i = si;
        // Main Crux of the Problem Lies Here
        for(; i<=mid-1; i++){
            while(j<=ei && nums[i]>(2*(long)nums[j])){
                j++;
            }
            count+=(j-(mid));
        }
        i = si;
        j = mid;
        int index = 0;
        vector<int> result(ei-si+1);
        while(i<=mid-1 && j<=ei){
            if(nums[i]<=nums[j]){
                result[index] = nums[i];
                i++;
            }else if(nums[i]>nums[j]){
                result[index] = nums[j];
                j++;
            }
            index++;
        }
        while(i<=mid-1){
            result[index++] = nums[i++];
        }
        while(j<=ei){
            result[index++] = nums[j++];
        }
        index = 0;
        for(i = si; i<=ei; i++){
            nums[i] = result[index++];
        }
        return;
    }
    
    
    void mergeSort(vector<int> &nums, int si, int ei, int &count){
        if(si>=ei){
            return;
        }
        int mid = si+(ei-si)/2;
        mergeSort(nums, si, mid, count);
        mergeSort(nums, mid+1, ei, count);
        merge(nums, si, ei, mid+1, count);
        return;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergeSort(nums, 0, n-1, count);
        return count;
    }
};
