
>>>>>>striver
class Solution {
public:
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
    
};

>>>>>>>>

code 2: same as above
// condition , each number can be used only once

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(can.begin(),can.end());
        
        comb_sum_bt(can, temp,target,0,res);
        
        return res;
    }
private:
    void comb_sum_bt(vector<int>& can,vector<int>temp,int remain,int index , vector<vector<int>>& res){
        if(remain == 0){
            res.push_back(temp);
            return;
        }
        
        for(int next_index = index ; next_index<can.size();next_index++){
            if(next_index>index && can[next_index]==can[next_index-1]){
                continue;
            }
            int ele = can[next_index];
            
            if(remain-ele < 0){
                break;
            }
            
            temp.push_back(ele);
            comb_sum_bt(can,temp,remain-ele,next_index+1,res);
            temp.pop_back();
        }
    }
    
};
