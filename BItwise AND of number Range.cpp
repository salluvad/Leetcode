///
given two numbers M and N , find the And of all numbers in that range 
////
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count =  0 ;
        while(left!=right){
            left=left>>1;
            right= right>>1;
            count++;
        }
        
        return left<<count;
    }
};

/*
lets take 16 and 19 
16=  10000
19 = 10011

MSB three bits are commn , so our answer will have these 3 bits same 

LSB two bits are flipped , so in the answer they will be zero 

so we shift left to see how many bits are flipped and right shift those many times (zeros will be added on right shift same as and operation of flipped bits )

*/
