class Solution {
public:
 /*   vector<vector<int>> dp;
    int helper(string word1,string word2,int m ,int n){
        if(m==0){
            return n;
        }
        if(n==0){
            return m;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        //other wise we have 3 operatios , insert , delete , replace
        if(word1[m-1]==word2[n-1]){
            return dp[m][n]= helper(word1,word2,m-1,n-1);
        }  
        return dp[m][n]= 1+min(helper(word1,word2,m,n-1),min(helper(word1,word2,m-1,n),helper(word1,word2,m-1,n-1))) ;
    }
    int min_recur(string word1,string word2){
        int m = word1.size();
        int n = word2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return  helper(word1,word2,m,n);
    }
  */  
    int dp_tab(string word1,string word2 , int m , int n){
        int dp[m+1][n+1];
        for(int i = 0 ;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j] = i;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1+ min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        // recursive
     //  return min_recur(word1,word2);    // this will give TLE error , we can add memo and try  , it works but we can still improve runn time by tabulation method
        
      return dp_tab(word1,word2 ,word1.size(),word2.size()); 
    }
};
