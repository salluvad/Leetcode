class Solution {
public:
    string reverseWords(string s) {
      string ans = "";
      string temp = "";
      int left = 0;
      int right = s.size()-1;
    
      while(left<=right){
          char ch = s[left];
          if(ch!= ' '){
              temp+=ch;            
          } else if (ch == ' ' && temp!=""){     // >>>> second condition check to prevent trailing spaces 
              if(ans==""){
                  ans = temp;
              } else {
                  ans= temp+ " " +ans;
              }
              temp="";
          }
            left++;       
      }
        
     //last word ;
        if(temp!=""){
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
        }
        
        return ans;
        
        
     }
};
