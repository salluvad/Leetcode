class Solution {
public:
    int minLength(vector<string> s){
        int min = s[0].size();
        for(int i = 1 ; i< s.size();i++){
            if(min<s[1].size()) {
                min = s[1].size();
            }
        }
        return min;
    }
    string longestCommonPrefix(vector<string>& strs) {
        //char by char matching algo
        int min_len = minLength(strs);
        string res;
        int n = strs.size();
        
        for(int i = 0 ; i<min_len ; i++){
            char c = strs[0][i];
            for(int j = 1;j<n ; j++){
                if(c!=strs[j][i]){
                    return res;
                } 
            }
     
            res.push_back(c);
            
            
        }
        return res;
        
    }
};
