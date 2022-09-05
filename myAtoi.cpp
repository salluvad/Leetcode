class Solution {
public:
    int myAtoi(string s) {
        
        int num = 0;
        int n = s.size();
        int i = 0;
        //remove leading white space
        while( i<n && s[i] == ' '){
            i++;
        }
        //store the sign
        int sign  = 1;
        if( i < n && (s[i] == '-' || s[i] == '+')) {
            sign = 1-2*(s[i] == '-');
            i++;
        }
        //check for valid input 
        while(i<n && s[i]>='0' && s[i] <='9') {
            //check for overflow
            if ((num>INT_MAX/10 )|| num == INT_MAX/10 && (s[i]-'0')> INT_MAX%10){
                return (sign == 1) ?INT_MAX:INT_MIN;
            }
               
                              
            //calc. the num
            num = num*10+(s[i]-'0');
            i++;
            
        }
        return sign*num;
    }
};
