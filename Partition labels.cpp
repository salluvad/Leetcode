/////

https://leetcode.com/problems/partition-labels/

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
/////


class Solution {
public:
    vector<int> partitionLabels(string s) {
        // idea is to keep track of last occurance of character in the string 
        // so we maintain a hash map to store the last location
        
        unordered_map<char,int> hm;
        
        for(int i = 0 ; i<s.size();i++){
            hm[s[i]-'a']=i;
        }
        
        //as we traverse the string , we keep updating end variable and size variable 
        vector<int> ans ;
        int size = 0;
        int end = 0;// need to keep track of patrtion index
        
        for(int i = 0 ; i<s.size();i++){
            size++;
            end = max(end,hm[s[i]-'a']);
            if(i == end){
                ans.push_back(size);
                size = 0 ;
            }
        }
        return ans;
    }
};
