//modified Boyer moore 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2=0;
        int cand1=INT_MIN;
        int cand2=INT_MIN ;
        vector<int> ans;
        
        for(auto n : nums){
            //check for cnd1 and cand 2
            if(cand1!=INT_MIN and cand1==n) {
                 count1++;
             } else if (cand2!=INT_MIN and cand2==n) {
                  count2++;
               }
             else if(count1==0){
                 cand1=n;
                 count1++;
             } else if (count2 == 0) {
                 cand2 = n;
                 count2++;
             } else {
                 count1--;
                 count2--;
             }
        }
        // second pass to verify the maj element
        int c1=0;
        int c2=0;
       
        for(auto n:nums){
            if(cand1!=INT_MIN and cand1 == n) c1++;
              if(cand2!=INT_MIN and cand2 == n) c2++;           
        }
        
        int n = nums.size();
        if(c1>n/3) ans.push_back(cand1);
        if(c2>n/3) ans.push_back(cand2);
         
        return ans;
         }
        
    
}
