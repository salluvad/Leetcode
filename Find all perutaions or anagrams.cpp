////

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

////


class Solution {
public:
    vector<int> findAnagrams(string s1, string s2) {    
        
         vector<int> ans;
         // if size of s1 > s2 , return false 
         if(s2.size() > s1.size())
            return ans;
        //check for all substrings of size s1 and compare their freq maps 
        
        vector<int> mp1(26);    // for s1  
        vector<int> mp2(26);     // for s2
        int i = 0 ;
         for( ;i<s2.size();i++) {    // first window
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;          
        }
        
        if(mp1 == mp2) {
            cout << "i " << i << endl;
            ans.push_back(0);
        }
              
        // search remaining windows
        for(;i<s1.size();i++){
            //remove the out of window char 
            mp1[s1[i-s2.size()]-'a']--;
            mp1[s1[i]-'a']++; 
            
            if(mp1 == mp2) {
                  cout << "i " << i << endl;
                 ans.push_back(i-s2.size()+1);
              
            }   
        }
        return ans;
        
    }
};
