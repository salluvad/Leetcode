/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

*/



class Solution {
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j==n-1 || i==m-1)
                    dp[i][j]=1;
                else{
                  dp[i][j]=dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
    
};
