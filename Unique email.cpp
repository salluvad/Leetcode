//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;
        for(auto s:emails){
            int n = s.size();
            string temp = "";
            for(int i = 0 ;i<n;i++){
                if(s[i]=='.'){
                    continue;
                } else if(s[i]=='+'){
                    while(s[i]!='@'){
                        i++;
                    }
                    temp+=s.substr(i);
                    break;
                } else {
                       if(s[i]=='@'){
                           temp+=s.substr(i);
                           break;
                       }
                       temp+=s[i];
                }
            }
            cout<<temp<< endl;
            uniq.insert(temp);
        }
        return uniq.size();
    }
};
