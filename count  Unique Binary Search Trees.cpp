class Solution {
public:
    int numTrees(int n) {
        // we use Dynamic programming
        // consider each number as root and find the total trees
        vector<int> dp(n+1,0);
        //base case 
        //for n=0 >> total trees 1
        //for n=1 >> total trees 1
        dp[0]=1;
        dp[1]=1;
 
        for(int i = 2 ;i<=n;i++){
            for(int j = 1;j<=i;j++){
               dp[i]+=dp[j-1]*dp[i-j];   // left and right trees for that particular node eg >> 1 2 [3] 4 5 
            }

        }
        return dp[n];
        
    }
};
