void rotate(vector<int>& nums, int k) {
        // method 1 . geeks for geeks Juggling algo
    
        
            
    // method 2 . by reversing
        
     int len=nums.size();
     k=k%len;  // keep K with in bounds 
     reverse(nums.begin(),nums.end());
     reverse(nums.begin(),nums.begin()+k);
     reverse(nums.begin()+k,nums.end());   
     
    }
};
