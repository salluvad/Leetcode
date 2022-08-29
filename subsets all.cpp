//////////// method one works for with and with out duplicates /////////////
class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());   // this is not needed when you dont have duplicates 
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
}

void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (unsigned int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i-1])    // this is not needed when you dont have duplicates 
            continue; 
        
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}
};


//////////////////////// method 2 //////////////////////////

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
