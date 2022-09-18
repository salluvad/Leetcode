// infinity supply of coins to make a denomination amount

class Solution {
public:
  
    int recur(vector<int>& coins , int amount,int n){
        //base case 
        //if amount ==0
        if(amount <=0) return 0;
        //if coins are zero
        if(n>=coins.size()) return INT_MAX-1;
        
        int res = -1;
        
        if(coins[n]>amount){
            //dont take 
            res = recur(coins,amount , n+1);
        } else {
            res = min(1+recur(coins,amount-coins[n],n),recur(coins,amount , n+1));
        }
        return res;
    }
    int dp_sol(vector<int>& coins , int amount){
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        
        //fill the first row , coins on rows and amount on col
        for(int i = 1 ; i<=amount;i++){
            dp[0][i]=INT_MAX-1; // we need infinity coins if we have no coins to make that amount
        }
        
        //fill the first col , if amount is zero ,we need zero coins to make the amoint zero
        for(int i = 0 ; i<=coins.size();i++){
            dp[i][0] = 0;
        }
        
        //fill the remaining cells , two case include and exclude
         for(int i = 1;i<=coins.size();i++){
             for(int j = 1;j<=amount;j++){
                 if(coins[i-1]>j){
                     dp[i][j]=dp[i-1][j];
                 }else dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
             }
         }
        
        return dp[coins.size()][amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        // recursive
      /*  int ans;
        ans=recur(coins,amount,0);
        return (ans ==INT_MAX-1)?-1:ans;
       */ 
        // dp
        int res ;
        res = dp_sol(coins,amount);
        return (res ==INT_MAX-1)?-1:res;
    }
};
