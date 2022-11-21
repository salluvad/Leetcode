https://leetcode.com/problems/unique-length-3-palindromic-subsequences/




class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // we need a sub sequence , so we need to find out the first occurance and last occurance of ssame char 
        // then the unique chars between them form pallindrome of Size 3
        
        unordered_map<char , pair<int,int>> hm;
        
        //fill the hashmap
        for(int i = 0 ; i<s.length();i++){
            if(hm.find(s[i])!=hm.end()){
                //second occurance 
                hm[s[i]].second=i;
            } else {
                hm[s[i]] = make_pair(i,-1); //first occurance and last occurance is not known as of here 
            }
        }
        
        // now count the unique chars between a pair of same chars 
       
        int max= 0;
        for(auto p :hm) {
            auto item = p.second;
            auto left = item.first;
            auto right = item.second;
            if(right !=-1){  // there is an second instance
                unordered_set<char> uniq;
                for(int i = left+1 ; i<right;i++){
                    uniq.insert(s[i]);
                }
                 max+=uniq.size();
            }
           
        }
        
        return max;
    }
};
