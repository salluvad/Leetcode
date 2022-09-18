class Solution {
public:
    int recur(vector<int>& arr, int k,int index, int n,vector<int>& dp){
        //base case 
        if(index == n){
            return 0;
        }
        
        if(dp[index]!=0){
            return dp[index];
        }
        
        int len = 0;
        int sum = 0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        
        // we need to partion at diff lengths
        for(int j = index;j<min(n,index+k);j++) {
            //keep track of maximum element encounterd and lenght of partition 
            //so that total sum of that sub arrray is lenght * max ele
            len++;
            maxi = max(maxi,arr[j]);
            
            sum = maxi*len+recur(arr,k,j+1,n,dp);
            maxAns = max(maxAns,sum);
           
        }
        return dp[index]=maxAns;
    }
    
    // tabulation code
    int dp_tab(vector<int>& arr, int k){
        int dp[arr.size()+1];
        int n = arr.size();
        
        //base case 
        dp[n] = 0;
        
        //copy the recursion part
         // we need to partion at diff lengths
        for(int index = n-1;index>=0;index--) {
            int len = 0;
            int sum = 0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;

            // we need to partion at diff lengths
            for(int j = index;j<min(n,index+k);j++) {
                //keep track of maximum element encounterd and lenght of partition 
                //so that total sum of that sub arrray is lenght * max ele
                len++;
                maxi = max(maxi,arr[j]);

                sum = maxi*len+dp[j+1];
                maxAns = max(maxAns,sum);
           
             }
            dp[index]=maxAns;
           
        }
        return dp[0];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // striver DP-54
        // we can solve this using recusrion , since we need to try out at atll partitions lengths and pick the best among them 
        vector<int>dp(arr.size(),0);
       // return recur(arr,k ,0,arr.size(),dp);   // lets make it memo
        
        return dp_tab(arr,k);
    }
};
