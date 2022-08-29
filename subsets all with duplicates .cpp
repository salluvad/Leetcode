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
