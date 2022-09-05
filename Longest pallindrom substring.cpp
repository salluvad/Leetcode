class Solution {
public:
    string longestPalindrome(string str) {
        string res;
        int n = str.size();
        if (n < 2)
        return str;
        int max_len =1 ;
         int start = 0;
             for (int i =0 ; i<n; i++) {
                     int low = i-1;
                     int high = i+1 ;

                     while(high < n && str[i]==str[high]).         /// cases like abbbb
                         high++;
                     while(low >=0  && str[i]==str[low]).           /// ccccba
                           low--;
                     while(low >=0 && high <n && str[low]==str[high])
                          high++,low--;

                int len = high -low -1 ;

              if(max_len < len) {
                  max_len = len ;
                  start = low+1;
                }
         }

       res = str.substr(start,max_len) ;
       return res;
        
    }
};
