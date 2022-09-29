class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
       uint32_t rev = 0 ;
        int i = 32;
        while(i-- >0){
            rev<<= 1;
            
            rev |= n&1;
            
            n>>=1;
        }
        /*
         for (int i = 0; i < 32; i++) {   // this works as well
            rev <<= 1;
            rev |= n & 1;
            n >>= 1;
        }
        */
        return rev;
    }
};
