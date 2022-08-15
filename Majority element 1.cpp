class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // we can use a hashmap tp store the count 
         unordered_map<int,int> count;
        for(int i=0;i<(int)nums.size();++i){
            count[nums[i]]++;
        }
        for(int i=0;i<(int)nums.size();i++){
            if(count[nums[i]] > (nums.size())/2){
                return nums[i];
            }
        }
        return 0;
    }
};
