/////
https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

////

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // linear compelxtity alog , 
        // start from the target and see if we have that lement in any of the triplet 
         //if we find a triplet with values greater than target triplet we can skip that triplet 
        
        unordered_set<int> s;
        
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue;
            }
            
            for (int j = 0; j < 3; j++) {
                if (triplets[i][j] == target[j]) {       // check from target , target element should be present in any of the good triplets 
                    s.insert(j);
                }
            }
        }
        
        return s.size() == 3;
    }
};
