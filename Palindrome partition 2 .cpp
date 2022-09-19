Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
  
  class Solution {
public:
    int recur(string s , int n ,int index,vector<int>& memo){
        //base case 
        if(index ==n){
            return 0;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        int minCost = INT_MAX;
        int cost =0;
        
        for(int j = index;j<n;j++){
            if(isPalindrome(s,index,j)){
                cost = 1+recur(s,n,j+1,memo);
                minCost = min(minCost,cost);
           }
         }
            
        return memo[index]=minCost;
    }
    
    int tab_dp(string s){
        int n = s.size();
        vector<int> dp(n+1,0);
        
        //base case
        dp[n] = 0;
        
        //state variable is i
        for(int i = n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int j = i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    int cost = 1+dp[j+1];
                    minCost = min(minCost,cost);
               }
         }
            
        dp[i]=minCost;
        }
        return dp[0]-1;
    }
    
    bool isPalindrome(string& s , int start , int end ){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
           
        }
         return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> memo(n,-1);
        return recur(s,n,0,memo) -1;   // subtract 1 beacuse we are doing extra partion at the end of the string , like the base case "A| B | c |<< one partion after c"
        
        //tabulation dp
       // return tab_dp(s);
    }
};
