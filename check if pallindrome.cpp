////

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

////



class Solution {
public:
    bool isPalindrome(string s) {
      for(int i = 0,j = s.size()-1 ; i<j ;i++,j--){
          // move i if its no a alpha-numeric
          while(i<j and !isalnum(s[i])){
              i++;
          }
          //do the same for j
           while(i<j and !isalnum(s[j])){
              j--;
          }
          
          if(tolower(s[i])!=tolower(s[j])){
              return false;
          }
      }
        return true;
    }
    
};
