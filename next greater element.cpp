class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // we use stack ., we start form end and start filling the stack with greater elements in increasing order 
        // for every elemnet we remove smaller elements from satck and insert the current element 
        
        // for circular array , 
        // 1.   we imagne that we concate the array twice and do the same approach 
        // so we mod the indexex by n
        //2. we prefill the stack in reverse order from the end , so we willsee the next greater from end index 
        
        int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> s;
        
        for(int i = nums.size()-1; i >= 0; i--)
            s.push(nums[i]);
        
       /* for(int i = nums.size()-1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums[i])
                s.pop();
            
            if(s.empty()) nge[i] = -1;
            else nge[i] = s.top();
            
            s.push(nums[i]);
        }*/
        
        for(int i = n-1 ; i>=0;--i){
            
                //remove all the smaller elements in stack
                while(!s.empty() and s.top()<=nums[i]){
                    s.pop();
                }
                //add the curr element
       
                if(!s.empty()) nge[i]=s.top();
                              
            
                s.push(nums[i]);
                           
        }
        
        return nge;
    }
};
