class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> map;
        for(int i = 0  ; i <n ; i++){
            map[nums[i]]++;
        }
        for(int i = 1  ; i <=n ; i++){
            if(map[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
