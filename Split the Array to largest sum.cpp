////////////////////

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.



///////////////////
class Solution {
public:
    int dp[1005][53] ;
    int recur(vector<int>& nums, int m,int index){
        int sum = 0;
        int ans = INT_MAX;
        //base case 
        if(m==0){  // zero spilts left
            for(int j = index; j < nums.size(); j++) {
                sum += nums[j];
            }
            return sum;
        }
        if(dp[index][m] != -1) {
            return dp[index][m];
        }
        
        for(int j = index ; j<nums.size();j++){
            sum += nums[j];
            ans = min(ans, max(sum, recur(nums,m - 1,j+1)));
        }
        
        return dp[index][m]=ans;
    }
    
    bool possible(vector<int> & nums, int m , long long barrier){
        long long sum = 0 ;
        int split_count=1;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]>barrier || split_count>m){
                    return false;
                }
            if(sum+nums[i]>barrier){
                split_count++;
                sum = nums[i];     
                
            } else {
                sum+=nums[i];
            }
                  
        }
        
        return (split_count <= m);
       
    }
    int Bin_Search(vector<int>& nums, int m) {
        // we need to create a search space 
        // min value which will be the part of the subset is the largest in the arr  and max value is sum of all values 
        long long left =0 ,right=0;
        
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        cout << left << " <=left and right=>  "<< right << endl;
        while(left<right){
           long long mid = left+(right-left)/2;
            if(possible(nums,m,mid)){
                right = mid;
            }else {
                left = mid+1;
            }
        }
        return left;
    }
    
    int splitArray(vector<int>& nums, int m) {
          //memset(dp, -1, sizeof dp);
        //  return recur(nums,m-1 ,0);    // recur + meo gives TLE , we can minimize the time by using prefix sum array to cal sum between index 
        //optimized is either DP tabulation or using Binary search 
        return Bin_Search(nums, m);
        
    }
};
