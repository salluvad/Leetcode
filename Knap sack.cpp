// recusion code\

 int KS(int wt[],int item[],int W , int N){
  // base case if cap is o or Num of item is zero
   if(W==0 || N ==0){
     // total profit is zero
     return 0;
   }
   // second case if curr element is greater than current capacity of sack
   if(wt[N-1] > W){
     //we need to skip that item 
       return KS(wt,item,W,N-1)
   }
   //other wise 
   
   return max(KS(wt,item,W,N-1),profit[N-1]+KS(wt,item,W-wt[N-1],N-1));
   
 }

//// DP
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
