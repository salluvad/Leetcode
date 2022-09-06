//geeksforgeeks

class Solution {
public:
    
    /*// this will cause time limit exceeded error
    int min_recur(string s, int l , int h){
        /// base case 
        if(l>h) return INT_MAX;
        if(l==h) return 0;   // one char
        if(l==h-1) return (s[l]==s[h]?0:1);   // two chars 
        
        return (s[l]==s[h])?
                           min_recur(s,l+1,h-1)
                           :(min(min_recur(s,l+1,h),min_recur(s,l,h-1))+1);
    }
    int minInsertions(string s) {
        // brute force is using recursion
        return min_recur(s,0,s.length()-1);
    }
    */
    
    int minInsertions(string s) {
        // brute force is using recursion
        int n = s.length();
        
        //create a dp array
        int dp[n][n] , l,h , gap ;   // gap goes from 1->sizeof string
        memset(dp,0,sizeof(dp));
        
        //fill the dp table
         // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            dp[l][h] = (s[l] == s[h])?
                        dp[l + 1][h - 1] :
                        (min(dp[l][h - 1],
                             dp[l + 1][h]) + 1);
        
    return dp[0][n-1];
    }
};
