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
