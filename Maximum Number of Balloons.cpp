//Given a string text, you want to use the characters of text to 
form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
/////

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // count the frequency of the chars 
        //balloon  , 
        //we need to see how many instances of balloons we can make , so freq of L and O is made half
        // beacuse we need two of each
        // find the thresold i,e nin of all frequecies
        
        unordered_map<char,int> mp;
        for(int i = 0 ; i<text.length();i++){
            mp[text[i]]++;
        }
        
        //return min_freq;
        return min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
    }
};
