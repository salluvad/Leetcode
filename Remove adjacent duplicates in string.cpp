class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(int i = 0 ; i<s.length();i++){
            if(!res.empty() and s[i]==res.back()){
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
    
};
