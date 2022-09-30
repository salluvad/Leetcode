Design an algorithm to encode a list of strings to a string. 
 The encoded string is then sent over the network and is decoded back to the original list of strings.
  
  //algo:
  append the length of each string before it ans use [ and ] to enclose the string in it.
  
  
  ////



class Codec {
private:
    string encode_helper(string s){
        return to_string(s.length())+ "[" + s + "]" ;  
      // we need to add extra [ ] because , for conditions like "0" , we encode it as "10" if we dont use [ ] ,
      //so when finding the num part in decode , we end up considering it as number rather than string 
        
    }
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // encode the lenght of each str before the string and put the string in [ ]
        string res;
        
        for(auto str:strs){
            res+=encode_helper(str);
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0 ;
        while(i<s.length()){
            char ch = s[i];
            int num = 0;
            
            while(i<s.length() and ch >='0' and ch <='9'){   // get the number portion
                num = num*10+(ch-'0');
                i++;
                ch = s[i];
            }
            num = num+2 ; // to account for brackets;
            string orig = s.substr(i+1,num-2);
            ans.push_back(orig);
            i+=num;
        }
        return ans;
    }
};
