class Solution {

  The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
  
  Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
  ///////////////////
  
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> s;
        // lets keep a map which stores next greater for all elements in nums2 
        map<int,int> mp;
        
        vector<int> res(nums1.size(),-1); // ans for nums 1 array
        
      //loop through all elemnets of nums 2 
        //its a monotonic stack , insert elements into keep if curr elements is smaller than top of stack
        
        for(int i = 0 ; i< nums2.size();i++){
            //curre ele
            int curr = nums2[i];
            
            while(!s.empty() and s.top() < curr){
                //pop and add ito map
                mp[s.top()] = curr;
                s.pop();
            }
            s.push(curr);
            
        }
        
        // iterate through  nums1 array and find the nge 
        for(int i = 0 ; i<nums1.size();i++){
            int curr = nums1[i];
            if(mp.find(curr)!=mp.end()){
                res[i] = mp[curr];
            }
        }
        
        return res;
    }
};
