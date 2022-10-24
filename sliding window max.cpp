class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // two ways 
       // using heap , and using double linked list(deque)
        // first method >>>>
        // to add an element in a heap of size k costs \log(k)log(k), that means \mathcal{O}(N log(k))O(Nlog(k)) time complexity for the solution.
         //
     /*   priority_queue<pair<int,int>> heap; //Max_Heap to find maximum in a sliding window
        // insert in Pairs of {val,index} in heap 

        vector<int> ans;    //Stores all maximum values for all sliding windows
        
        for(int i=0;i<nums.size();++i)
        {
            while(!heap.empty() and heap.top().second <=(i-k)) { //Pop the root (max_element),if it is out of sliding window
                heap.pop();
            }
            heap.push(make_pair(nums[i],i));    //Push current element (along with its index) into the heap
            if(i>=k-1)      //Store max in the window if we have a valid window (based on size K)
                ans.push_back(heap.top().first);       
        }
      */  
        // second method >> using deque   >>>O(N);
      /*  Algo :1.pop from front if its ouisde the wondow
              2.maintain dll in decreasing order
              3.push the node  , check from right for the point 2  (DSC odeer).
              4. for each window add max to array
              */
        
         deque<pair<int,int>> dq;
         vector<int> ans; 
         for(int i=0;i<nums.size();++i)
          {
            if(!dq.empty() and dq.front().second<=(i-k)) {
               dq.pop_front();
            } // out of window size
            while(!dq.empty() and dq.back().first<nums[i]) { //Maintain elements in DSC order
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[i],i));
            if(i>=k-1){
            ans.push_back(dq.front().first);
            }
         
         }
        return ans;
    }
};



/////


using deque   >>>O(N);
      /*  Algo :1.pop from front if its ouisde the wondow
              2.maintain dll in decreasing order
              3.push the node  , check from right for the point 2  (DSC odeer).
              4. for each window add max to array
              */
        
         deque<pair<int,int>> dq;      /// val and index 
         vector<int> ans; 
         for(int i=0;i<nums.size();++i)
          {
            if(!dq.empty() and dq.front().second<=(i-k)) {
               dq.pop_front();
            } // out of window size
            while(!dq.empty() and dq.back().first<nums[i]) { //Maintain elements in DSC order , since there is no need of storing 
                                                              //smaller elements if we need max of window.
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[i],i));
            if(i>=k-1){
            ans.push_back(dq.front().first);
            }
         
         }
        return ans;
    }
