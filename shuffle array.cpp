Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].






class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //idea is to use the bit manipulation 
        // constarints >> value is <1000 (means it can be represented in 10 bits 
        
        // we can store two numbers in one location (32 bit)
        // first number is shifted by 10 and the second number by doing logical or with first number 
        int i ,j ;
        int x ,y;
        //n is half size of array , since question says array size 2n
        
        //first loop . make xy pairs from first and second half
        for(i = 0 ; i <n ;i++) {
            nums[i] = nums[i]<<10;
            nums[i] = nums[i] | nums[i+n] ;
        }
        
        j = 2*n-1 ;
        //start filling from back , we dont overwrite the front entries 
        for(i = n-1 ; i>=0;i--){
            y = nums[i] & 0x3FF; //last 10 bits 
            x = nums[i] >> 10;
            nums[j] = y;
            nums[j-1] = x;
            j-=2;
        }
        
        return nums ;
    
        
    }
};
