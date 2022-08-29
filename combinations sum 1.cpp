class Solution {
public:
   void find_comb (int ind, vector<int> & arr, int target ,vector<vector<int>> & ans, vector <int> & ds) {
       
       if(ind == arr.size()){
           if(target == 0){
               ans.push_back(ds);
           }
           return ;
       }
    // recursion pick the elemnet or not pick 
       if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        find_comb(ind,arr,target-arr[ind],ans,ds);
        ds.pop_back();
       }
        
       //not pick the ele
       find_comb(ind+1,arr,target,ans,ds);
           
   }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        
        find_comb(0,candidates,target,ans,ds);
        
        
        return ans;
    }
};
