//Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
  No two characters may map to the same character, but a character may map to itself.

/////
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      // create a mapping of each char of first string to second string 
      // if a char exists in map and its not correct maping , return false 
        map<char,char> mpStoT;
        map<char,char> mpTtoS;
        
        if(s.size() != t.size()) return false ;
        
        for(int i = 0 ;i<s.size();i++){
            if(mpStoT.find(s[i])!=mpStoT.end()  or mpTtoS.find(t[i])!=mpTtoS.end()){
                if(mpStoT[s[i]] !=t[i] or mpTtoS[t[i]] !=s[i] ){
                    return false;
                }
            } else {
               
               mpStoT[s[i]] = t[i] ;
               mpTtoS[t[i]] = s[i] ;
            }
        }
        return true;
        
    }
};
