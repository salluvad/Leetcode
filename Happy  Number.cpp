//////
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

//////



class Solution {
public:
    bool isHappy(int n) {
        
         unordered_map<int,int> tmp;
        
        while(n != 1)
        {
            if(tmp[n] == 0)               // we push numbers into the hash map to check if we are running in a loop or not 
                tmp[n]++;
            else
                return false;
            
            int sum = 0;
            while(n != 0)  
            {
                sum += pow(n % 10,2);           // sum of square sof individual digits
                n = n / 10;  
            }
            
            n = sum;
        }
        
        return true;
    }
};
