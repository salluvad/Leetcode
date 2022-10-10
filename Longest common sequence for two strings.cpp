// 
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
    
//////
///recursion. + memo
class Solution {
public:
    int helper(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        if(i == text1.size()) return 0;
        if(j == text2.size()) return 0;
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = max(ans, 1 + helper(i+1, j+1, text1, text2, dp));
        } 
        ans = max(ans, helper(i, j+1, text1, text2, dp));
        ans = max(ans, helper(i+1, j, text1, text2, dp));
        
        dp[i][j] = ans;
        return ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, text1, text2, dp);
    }
};

  // tabulation method , both works well
    
    int longestCommonSubsequence(string text1, string text2) {
    // tabulation method
         int m = text1.size();
         int n = text2.size();
         int L[m + 1][n + 1];
 

        for (int i = 0; i <= m; i++)
         {
            for (int j = 0; j <= n; j++)
             {
                  if (i == 0 || j == 0)
                          L[i][j] = 0;
 
                    else if (text1[i - 1] == text2[j - 1])
                         L[i][j] = L[i - 1][j - 1] + 1;
    
                 else
                         L[i][j] = max(L[i - 1][j], L[i][j - 1]);
             }
         }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
    }
    
};
