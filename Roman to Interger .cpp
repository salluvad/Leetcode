// cal value at  s1= s[i] and s2=s[i+1] , 
//if s1>s2 (eg XV) result = res+S1
// else eg (XL) res= res+s2-s1. (s1=10 , s2 = 50) res = 0+50-10 = 40
class Solution {
public:
int value(char s) {
switch(s)
        {
        case 'I' :
                return 1;
                break;
        case 'V' :
                return 5;
                break;
        case 'X' :
                return 10;
                break;
        case 'L' :
                return 50;
                break;
        case 'C' :
                return 100;
                break;
        case 'D' :
                return 500;
                break;
        case 'M' :
                return 1000;
                break;
        default:
                return 0;

    }
}
    int romanToInt(string s) {
       int i =0;
       int res = 0;
       int s1 =0 , s2=0; 
       int n = s.length();
        
        //compare i and i+1 value 
        for(int i =0 ; i< s.length();i++) {
          s1 = value(s[i]);
          cout << "S1" << "   " << s[i]  << " "<< s1  << " " <<  endl;
          if(i+1 < n){
              s2 = value(s[i+1]);
               cout << "S2" << "   " << s[i] << " "<< s2  << " " << endl;
                if(s1>=s2) {
                   res = res+s1;
                } else {
                   res = res+s2-s1;
                   i++;
                 }
          } else res = res+s1;
           
        }
        return res;
        
    }
};
