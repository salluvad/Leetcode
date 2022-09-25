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
