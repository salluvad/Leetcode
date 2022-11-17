Given an array arr, replace every element in that array with the greatest element among the elements to its right, 
and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
  
  
  //////
  
  class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // we need to traverse in reverse 
        // eg new value at 0 is max of (arr[1], new[1])
        
        //base case new value for last index is -1
        
        int n = arr.size();
       // vector<int> new_arr(n,-1);  // we can eliminate this extra space by using a max variable 
        int max = -1;
       // new_arr[n-1] = -1;
        for(int i = n-1;i>=0;i--){
            //new_arr[i] = max(new_arr[i+1],arr[i+1]);
           // store the current values in some temp variable 
            int temp = arr[i];
            arr[i] = max;
            max = std::max(temp,max);
           
        }
        
       
        return arr;
    }
};
