///////
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
///////
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
          for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits ;
    }
};
