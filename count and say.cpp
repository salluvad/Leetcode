// 1
//11
//21
//12 11.         one two and one one 
//11 12 21



class Solution {
public:
    string countAndSay(int n) {
        // Base cases
    if (n == 1)      return "1";
    if (n == 2)      return "11";
 
        
    string str = "11";
    
    
    for(int i = 3 ; i<=n;i++){
        
     str += '$' ; // to run the loop for one extra len
     string tmp = "";
        
     int len = str.length(); 
     int count = 1 ;
     
     //
     for(int j = 1 ; j<len ;j++){
         if(str[j]!=str[j-1]){
             tmp+=count+'0';
             tmp+=str[j-1];
             count = 1;
             
         } else count++;
     }
     
       str = tmp; 
    }
   return str;
   
    }
};
