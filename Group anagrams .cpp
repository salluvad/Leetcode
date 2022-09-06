// anagram is diff arrangement of same word 
//so if we sort all anagrams , it will be the same 
//so we use that string as key 
//and populate the map with its corrospodning groups 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string> > mymap;
        int n = strs.size();
        string temp;
        //optimization is not to sort , instead use bit map as key 
        //map<map<char,int>,vector<string>> map_1
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)
            result.push_back(itr->second);
        
        return result;
        
    }
};
