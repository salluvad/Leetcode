/// brute force is filnd all sub strings and find if duplicates exist

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

//// optimzed 1 , two pointer approach , keep deleting chars from left  till there are no duplicates of the current sub string

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}




//sliding window , tow poinyer L and R , 
//creata a map of char and index of that char as value or simple array of 256 init to -1 
//while incrementing R , check if its not -1 in arr , then add the index to that positin , map[s[r]] = r(moving index )
//if its in the map , means there is a duplicate , move the left pointer 
// in every iteration find the max lenght max{len,R-L+1}


#include <iostream>
using namespace std;

class Solution {
public:
    int max(int a , int b) {
        return (a>b) ?a :b;
    }
    int lengthOfLongestSubstring(string s) {
        //two pointer method
        int L = 0;
        int R = 0;
        int n = s.size();
        //store the character index  in map , initialize to -1
        vector<int> Map(256 , -1);
        int len = 0;
        while(R<n){
            //if index present in map and it shluld not be between 
            //current left and right pointers 
            if(Map[s[R]] != -1) {
                //move the left pointer 
                L = max(L , Map[s[R]]+1 );
                
            }
            len = max(len , R-L+1);
            Map[s[R]] = R;
            R++;
            
          
        }
        return len ;
                
    }
};
