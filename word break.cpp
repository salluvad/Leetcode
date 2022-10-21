Given a string s and a dictionary of strings wordDict, return true 
  if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // cpy the dict to set for fatser access
        set<string> word_set(wordDict.begin(),wordDict.end());
        //create a dp array / memoization array
        vector<int> memo(s.length(),-1);
        
        //recursion helper
        return recur(s,word_set,0,memo);
    }
    bool recur(string s , set<string> &word_set , int start, vector<int>&memo) {
        //base case if we reached the end of string , means we found substring 
        //with that partion in the set in previous call
        if(start == s.length()){
            return true;
        }                                                       /// Time complexity is n(len of string) * n(for loop for each partion) * n (substr method)
        //use the previous calc val.                             // so total TC is o(n^3) , space is for memo array o(n) // biggest recursion tree + space for 
                                                                 // memo array
        if(memo[start]!=-1){
            return memo[start];
        }
        
        //main loop for breaking word at diff positions
        for(int end = start+1;end<=s.length();end++){
            if(word_set.find(s.substr(start,end-start))!=word_set.end() and
                recur(s,word_set,end,memo)) {
                
                return memo[start]=true; 
            }
        }
        return memo[start]=false;
        
    }
};

