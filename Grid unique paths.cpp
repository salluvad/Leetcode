// first brute force is recursion 

class Solution {
public:
     int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }
};


// second is recur + memo 

class Solution {
public:
     int countPaths(int i,int j,int n,int m,vector<vector<int>>& memo)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
         
       if(memo[i][j]!--1){
          return memo[i][j];
       }
        else return memo[i][j]= countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       countPaths(0,0,m,n);
       if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};

/// further optimization is tabulation method

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


/// mathematical approach 

if we observe in a smaller 2*3 grid , we need to take R R D , D R R and R D R . we need to take cols-1 rights and rows-1 downs 
so tota will be m-1+n-1 = m+n-2 = 2+3-2 =3 paths 

we need to choose m-1 from total or n-1 from toatl so   m+n-2 C m-1 or  m+n-2Cn-1.   >>>> 3C2 or 3C1 (for this example)

class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};
