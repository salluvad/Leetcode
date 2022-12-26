class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // neetcode 
        // sort the array and 
        // for each sliding window , left and right , check if we can make all the elements in 
        //the window same as element pointed by right pointer  with our given bugdet 
        
        sort(nums.begin(), nums.end());
        
        long res = 0, sum = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (l < r && sum + k < nums[r] * (r - l + 1)) {
                sum -= nums[l++];
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};
