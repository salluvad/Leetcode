Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.



class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        int res=0;
        for(int i :nums)
        {
            res+=mp[i];   // add the original pairs count with previously found value 
            mp[i]++;    // increment the count
        }
        return res;
    }
};
