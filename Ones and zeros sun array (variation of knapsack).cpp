class Solution {
    //https://www.youtube.com/watch?v=qkUZ87NCYSw
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> dp2; // in tabulation method 
    void count(string s, int& C_zero,int& C_one){
        for(int i = 0;i<s.size();i++){
            if(s[i]=='0'){
                C_zero++;
            }else C_one++;
        }
    } 
 /*   
    // this is derived from recursion + memoization  >> this gives TLE
    int helper(vector<string>& strs,int zero,int one,int index){
        //base case
        if(index==strs.size() || zero+one==0){
            return 0;
        }
        //two cases either consider that element or skip 
        // first find the #0f zeros and ones 
        int C_zero=0;
        int C_one=0;
        count(strs[index],C_zero,C_one);
        
        if(dp[zero][one][index]>0){
            return dp[zero][one][index];
        }
   
        int consider = 0;
        //consider only if required zero and one is greater than ones in this str
        if(zero>=C_zero and one >=C_one){
            
            consider = 1+helper(strs,zero-C_zero,one-C_one,index+1);
        }
        //dont consider/ skip
        int skip = helper(strs,zero,one,index+1);
        
        //return max(consider,skip);
        dp[zero][one][index] = max(consider,skip);
        
        return dp[zero][one][index];
    }
    */
    // we need DP tabulation method
    int helper2(vector<string>& strs,int m,int n){
        // we build on top of the idea that 
        //if we consider the string. the total number of zeros and ones 
        //will reduce by the count of zeros and ones in that string 
        //so we calc this for all substrings 
        for(string str:strs){
          int C_zero=0;
          int C_one=0;
          count(str,C_zero,C_one);
        // now the zeros reduced to m-C_zero and same for ones
            for(int zero = m ; zero>=C_zero;zero--){
                for(int one = n ; one>=C_one;one--){
                    dp2[zero][one] = max(1+dp2[zero-C_zero][one-C_one],dp2[zero][one]);
                }
            }
            
        }
        return dp2[m][n];
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        // lets try the recurisve sol , need to pass the starting index 
        int s= strs.size();
       dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(s+1,0)));
        dp2.resize(m+1,vector<int>(n+1,0));
       return helper2(strs,m,n);
    }
};
