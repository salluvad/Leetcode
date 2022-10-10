///////////
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
https://leetcode.com/problems/maximal-square/
//////////
class Solution {
public:
    int recursion (vector<vector<char>>& matrix){
        //input sanity check 
        if(matrix.size()==0){
            return 0;
        }
        
        int res = 0 ;
        
        // try from all positions of the matrix
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, helper(matrix, i, j));
            }
        }
        return res * res;
    }
    int helper(vector<vector<char>>& matrix, int i, int j) {
        //base cases check 
        if (i >= matrix.size() || j >= matrix[0].size()) return 0 ;
        
        if (matrix[i][j] == '0') return 0;
        
        // return 1 + min(bottom , right and diag directions )
        return min(min(helper(matrix, i, j+1), helper(matrix, i+1, j)), 
                   helper(matrix, i+1, j+1)) + 1;
        
    }
    
     int memoization(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
         
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, solve(matrix, mem, i, j));
            }
        }
        return res * res;
         
     }
     
    int solve(vector<vector<char>>& matrix, vector<vector<int>>& mem, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;
        if (mem[i][j] >= 0) return mem[i][j];
        if (matrix[i][j] == '0') return mem[i][j] = 0;
        mem[i][j] = min(min(solve(matrix, mem, i+1, j), solve(matrix, mem, i, j+1)),
                        solve(matrix, mem, i+1, j+1)) + 1;
        return mem[i][j];
    }
    
     
    int tabulation(vector<vector<char>>& matrix){
        // dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));  >> this is our core dp formula
        // our dp table is  always size onemore than our grid row+1 and col+1 , to take care of boundary cases 
        int rows = matrix.size();
        if(rows==0)
            return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
        int largest = 0;
        for(int i=1;i<=rows;++i)
        {
            for(int j=1;j<=cols;++j)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    if(largest < dp[i][j])
                        largest = dp[i][j];
                }
            }
        }
        return largest*largest;
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        //return recursion(matrix);  // this gives TLE
        //return memoization(matrix);   // this is accepted , but Tabulation is more efficient 
        return tabulation(matrix);
    }
};
