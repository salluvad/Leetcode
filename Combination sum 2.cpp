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
