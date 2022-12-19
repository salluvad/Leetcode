 Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
  
  class Solution {
private :
bool checkPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
public:
 bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (i < j) {
            // Found a mismatched pair - try both deletions
            if (s[i] != s[j] ){
                return (checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j));
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
};
