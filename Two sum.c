vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int curr_sum,b;
        unordered_map<int,int> M;
        for(int i=0 ;i<n;i++) {
            b=target-nums[i];
            if(M.find(b)!=M.end()){
                return {M[b],i};
            }
            M[nums[i]] = i;
                  
        }
        return{-1,-1};
    }
