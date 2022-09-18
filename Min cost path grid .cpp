class Solution {
public:
    int helper(vector<vector<int>>& grid, int m ,int n){
        //base case 
        if(m < 0 || n < 0){
            return INT_MAX;
        } else if(m == 0 and n == 0){
            return grid[m][n];
        } else 
            return grid[m][n] + min(helper(grid,m-1,n),helper(grid,m,n-1));
    }
    int recur(vector<vector<int>>& grid){
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        return helper(grid,m,n);
    }
    int dp_helper(vector<vector<int>>& grid){
        
        int rows = grid.size();
        if(rows==0)
            return 0;
        int cols = grid[0].size();
        vector<vector<int>>dp(rows , vector<int>(cols,0));
                             
        dp[0][0]= grid[0][0];
                              
        //fill the first row
        for(int i=1;i<cols;++i)
            dp[0][i] = dp[0][i-1] + grid[0][i]; 
                              
        //fill the first col
        for(int i=1;i<rows;++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
                              
        //rest of the matrix
        for(int i=1;i<rows;++i)
        {
           for(int j=1;j<cols;++j)
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }                    
                              
           return dp[rows-1][cols-1];                 
    }
    int minPathSum(vector<vector<int>>& grid) {
        // can be solved with recusion , it gives TLE , but lets try 
       // return recur(grid);
        
        return dp_helper(grid);
        
    }
};
