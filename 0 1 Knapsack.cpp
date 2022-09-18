// recusion idea
//decison tree is wither consider that or not 

int ks(int wt[],int val[];int W,int N){
    // base case 
   if(W ==0 || N ==0){
     return 0
   }
  //recursion tree
  if(wt[N-1]>W){
    return ks(wt,val,W,N-1):
  } else {
      return max( ks(wt,val,W,N-1),val[n]+ks(wt,val,W-wt[N],N-1));
  }   
}

// tabulation Dp
// we create a dp matric of size N+1 , W+1

dp[N+1][W+1]
//first case in above recursion 
if(i ==0 || j ==0){
  dp[i][j]=0;
  }
  //recursion tree
  else if(wt[i-1]>j) dp[i][j] = dp[i-1][j] //skip that item
  else dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[j-1]];
