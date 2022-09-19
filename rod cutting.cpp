//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int recur(int price[],int n,int index,vector<vector<int>> memo){
        //base case 
        if(index==0){
            return price[0]*n;
        } // means cut of lenght 1
        
        if(memo[index][n]!=-1){
            return memo[index][n];
        }
        //two case take and dont take 
        
        
        int notTake = 0+recur(price,n,index-1,memo);
        
        int take = INT_MIN;
        int rodlength = index+1;
        
        if(rodlength<=n){
            take = price[index]+recur(price,n-rodlength,index,memo);
        }
        return memo[index][n]= max(take,notTake);
    }
    int tab_dp(int price[],int n){
        
        
        vector<vector<int>>dp(n,vector<int>(n+1.0));
        
         //base case
         for(int i=0;i<=n;i++){
             dp[0][i]= i*price[0];
         }
         
         //variables are index and lenght
         for(int index = 1;index<n;index++){
             for(int N=0;N<=n;N++){
                    int notTake = 0+dp[index-1][N];
            
                    int take = INT_MIN;
                    int rodlength = index+1;
                    
                    if(rodlength<=N){
                        take = price[index]+dp[index][N-rodlength];
                    }
                     dp[index][N]= max(take,notTake);
             }
         }
        return dp[n-1][n];
    }
    int cutRod(int price[], int n) {
        //code here
        // recurisve
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
       // return recur(price,n ,n-1,memo);  // recur + memo >>. still gives TLE
        
        return tab_dp(price,n);
    }
};
