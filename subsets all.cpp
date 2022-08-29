class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subsets_bt(nums, ans, temp, 0);
        return ans;
    }
private:
    void subsets_bt(vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp, int start) {
        // goal, once we reach the end, add it to the result
        if(start == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // for every element we have two choices : keep it or drop it
        // choice 1, keep it
        temp.push_back(nums[start]);
        subsets_bt(nums, ans, temp, start + 1);
    
        
        // choice 2, drop it
        temp.pop_back();
        subsets_bt(nums, ans, temp, start + 1);
        
    }      
} ;
