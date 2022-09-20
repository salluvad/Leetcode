You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
  
  
  ///////
  
  class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // lets take two vectors to store the letter and digit logs 
        // we divide the logs in two parts first part is the identifier for eg dig1 anc let1 in "dig1 8 1 5 1","let1 art can" and second part is the actual content like "8 1 5 1" or "art can"
        vector<pair<string,string>> let;  //>> one for letter and other for digit
        vector<pair<string,string>> dig;
        
        for(auto log:logs){
            bool flag = false ; /// to identify the first space and seperate the log into two parts
            string key ="";
            string val = "";
            
            for(int i = 0 ; i<log.size();i++){
                
                //if we encounter first space
                if(flag == false && log[i] == ' '){
                    flag = true ;
                    continue;
                }
                
                
                //if curr char is not space and depending on flag , append to key ans val;
                if(flag ==false){
                    key+=log[i];
                } else {
                    val+=log[i];
                }
            }
            //put the key val in letter or digit vectors
            if(val[0]>='a' && val[0] <= 'z'){
                let.push_back({val,key}) ; // push them in reverse ordee , so we can sort them based on content
            } else {
                dig.push_back({key,val}); // digit logs can be in relative order 
            }
        } 
        
        //once all logs are pushed into the vectors 
        //sort them
        sort(let.begin(),let.end());
        // result array
        vector<string> ans;
        for(auto i : let){
            ans.push_back(i.second+" "+i.first);    // revrse it back 
        }
        
        for(auto i : dig){
            ans.push_back(i.first+" "+i.second);
        }
        
        return ans;
        
        
    }
};
