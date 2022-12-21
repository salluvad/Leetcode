You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
  
  
  class Solution {
public:
/*  sort the array to keep out minimum element at position and find the maximum subarrays that follow the condition.
the approach is similar to that of the sliding window solution of the two sum problem.
Whenever our sum is less than or equals to the target sum then we count the number of the subarrays.

Lets say our (right - left) is of length l then the solution in this array will be 2^(right - left) (take the element or dont take the element).
*/
int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = n-1;
    int ans = 0;
    int mod = 1e9 + 7;  // given in the problemm 
    
    vector<int> pow(n,1);
    
    for(int i=1; i<n; i++){
        pow[i] = (pow[i-1] * 2) % mod;   

    }
    
    while(l <= r){
        if(nums[l] + nums[r] > target){
            r--;
        }
        else{
            ans = (ans + pow[r - l]) % mod;
            l++;
        }
    }
    
    return ans;
}
};
