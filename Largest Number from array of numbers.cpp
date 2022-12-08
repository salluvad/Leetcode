Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"

  
  ///////
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0){
            return "";
        }

      int n = nums.size();
        for(int i = 0 ; i<n-1;i++){
            for(int j = i+1;j<n;j++){
                //append nums[i]num[j] and nums[j]num[i] and compare them 
                string ij = to_string(nums[i])+to_string(nums[j]);
                string ji = to_string(nums[j])+to_string(nums[i]);    // eg 3 , 34 >> we get 334 and 343
                
                if((ij)>(ji)){
                    continue;
                } else {
                    swap(nums[i],nums[j]);
                    
                }
            }
        }
        string res = "";
        for(auto it:nums){
        cout << it << " ";
        res+=to_string(it);
        }
        
        return res[0]=='0'?"0":res;    // this is for case like [0,0] >> we get "00"  but o/p should be "0";
    }
};
