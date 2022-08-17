// extension of two sum problem
//make al two sum pairs and store them in map
//now go through the array and and find in target-num[i]-num[j] exists in map
//if not add it to ans array , 
// cornr case ->remove duplicates , sort the array first and skip if num[i]==num[i-1]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        int n= nums.size();
        if(n<4)
            return ans;
     //sort the vector 
        sort(nums.begin(),nums.end());
        
     // create a map of two sum
        unordered_map<int, vector<pair<int, int> > > m;
        for(int i=0; i<n-1;i++)
                for(int j =i+1 ; j<n;j++)
                        m[nums[i]+nums[j]].push_back(make_pair(i,j));
        
      // find k and l
          
    for(int i=0 ; i<n-1;i++) {
        if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j = i+1 ; j<n;j++) {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
           
                int sum = target-nums[i]-nums[j];
                if(m.find(sum)!=m.end()){
                   for(auto it:m[sum]) {
                       int k = it.first;
                       int l = it.second;
                       if(k>j && l>k) { 
                       //Skip invalid cases
                       if(!ans.empty() and ans.back()[0]==nums[i] and ans.back()[1]==nums[j] and ans.back()[2]==nums[k] and ans.back()[3]==nums[l])
                       {
                           continue;
                        }
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);

                        } 
                       
                     }
    
        
                }
          }
      }
        return ans;
    }
    
};
