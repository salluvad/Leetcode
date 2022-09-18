// this is same as target sum in an array 
// here we divide the array into two equal sum partiotions 
//so our problem gets reduced to target sum is half od total sum

class Solution {
public:
    bool dfs(vector<int>& nums,int n , int target){   // we can add memoization to this , 
        // base case 
        if(target == 0){
            return true;
        }
        
        if(n ==0 || target <0){    // n== 0 , we can not split the array into two if we reached the satrting ele
            return false;
        }
        
        bool result = dfs(nums,n-1,target-nums[n-1]) || dfs(nums,n-1,target) ;
        
        return result;
        
    }
    
    bool dp_sol(vector<int>& nums,int n , int target){
        bool dp[n+1][target+1];
        memset(dp, 0, (n + 1) * (target + 1) * sizeof(bool));
        
        // base cases
        dp[0][0] = true;
        for(int i = 0; i <= n; i++)
         {
          for(int j = 0; j <= target; j++)
            {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
         }
        
        for(int i = 1 ; i<=n;i++){
            int curr = nums[i-1];
            for(int j = 1 ; j<=target;j++){
                if(j<curr){
                    //skip
                    dp[i][j]= dp[i-1][j];
                } else {
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-curr] ;
                }
            }
        }
        return dp[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        // we can reduce the problem to target sum is total sum by 2
        int total = 0;
        for(int i = 0 ; i< nums.size();i++){
            total+=nums[i];
        }
        if(total%2 !=0) return false  ; // for odd sum we ca not partion the array
        
        int target = total/2;
        int n = nums.size();
      //  return dfs(nums,n-1,target);
        
        return dp_sol(nums,n-1,target); // dp sol tabulation
    }
};
