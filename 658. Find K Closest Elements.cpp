Given a sorted integer array arr, two integers k and x, 
return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

//two methods of solving 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {  // method 2 O(log(N-k)+k)
        int left = 0 ;
        int right = arr.size()-k; // we have to find the window . not the value
        
        vector<int> res;
        
        while (left < right) {
            int mid = (left + right) / 2;  // mid is our left boundary of window
            if (x - arr[mid] > arr[mid + k] - x) {  // if the element just outside the window is closer to target , move the window to right 
                left = mid + 1;
            } else {
                right = mid;  // not mid-1 , becuase we need to keep mid as well in the window
            }
        }
        
        for(int i = left ; i<left+k ;i++){
            res.push_back(arr[i]);
        }
        
        return res;
        
    
    }
    
    
    vector<int> findClosestElements_1(vector<int>& arr, int k, int x) {
        /*
        O(log(N)+k).
        As a base case, if arr.length == k, return arr. 

Use binary search to find the index of the closest element to x in arr. Initailize two pointers left and right, with left set equal to this index, and right equal to this index plus one.

While the window's size is less than k, check which number is closer to x: arr[left] or arr[right]. Whichever pointer has the closer number, move that pointer towards the edge to include that element in our output.

Return the elements inside arr contained within the window defined between left and right.
         
        */
        vector<int> res;
        
        if(arr.size()==k){
            res = arr;
            return res;
        }
        
        // find the X in the arr , since its sorted we can use binary search
        int left = 0 ;
        int right = arr.size();
        int mid = 0 ;
        while(left<right){
            mid = (left+right)>>1;
            if(arr[mid]>=x){
                right = mid;
            }else{
                left = mid+1;
            }
            
        }
        
        // we found the elemnet ar right index , adjust left and right pointers
        left = left-1;
        right = left+1;
        
        //expand the window with in size of K
        while(right-left-1<k){
            //check for left boundary
            if(left ==-1){
                right++;
                continue;
            }
            
            //check for tie breaker condition 
            if(right == arr.size() or abs(arr[left]-x)<=abs(arr[right]-x)){
                left--;
            } else {
                right++;
            }
        }
        
        //copy the vector between left and right pointers 
        for(int i = left+1 ; i<right ;i++){
            res.push_back(arr[i]);
        }
        
        return res;
        
        
        
        
        
     }
};
