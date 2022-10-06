////
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a 
sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence 
from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.



////


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // we can solve this problem by considering each word as a node in graph 
        // whenever we want to find shorter distance type of solutions 
        //DFS always gives us polynomial coplexity , whereas dfs gives exponential 
        
        //we use BFS , words are nodes of the undirected graph wih same weight edges  
        
        
        //create a set and store all the words of dict in it                
        unordered_set<string> myset; // we need a set to keep track of already used words , a word can be used only once 
        bool isPresent = false; //Checks if endWord is present in Dict
        
        //
        //Insert all words from Dict in myset  and do some sanity checks
        //if end word is not in the dict , then retun 0;
        for(auto word: wordList)
        {
            if(endWord.compare(word)==0)
                isPresent = true;
            myset.insert(word);    //Insert word in Dict
        }
        if(isPresent==false)    //endWord is not present in Dict
            return 0;
        
        //BFS 
        queue<string> q;
        q.push(beginWord);
        int depth = 0;   // depth is the shortest path to reach the end word , i.e levels/layers
        
        while(!q.empty()){
            depth++;
           int lsize = q.size();
            while(lsize--){
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth words
                 for(int i=0;i<curr.length();++i)  //For each index
                {
                     string temp = curr;
                    for(char c='a';c<='z';++c)  //Try all possible chars
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;   //Skip the same word
                         if(temp.compare(endWord)==0)
                            return depth+1; //endWord found
                         if(myset.find(temp)!=myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                 }               
            }          
        }
         return 0; 
     }    
      
    
}
