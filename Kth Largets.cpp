class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
         priority_queue<int> max_heap;

        int n = arr.size();

        for(int i =0 ; i<n ; i++)
              max_heap.push(arr[i]);

        for(int i =0 ;i<k-1;i++) {
                max_heap.pop();
            }
          return max_heap.top();
        
    }
};
