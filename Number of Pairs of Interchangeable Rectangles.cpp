class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // keep a hashmap of ratio to rectangles 
        unordered_map<double , int> hm;
        long long ans = 0;
        
        for(auto it:rectangles){
            double ratio = (double )it[0]/it[1];
            ans+=hm[ratio];
            hm[ratio]++;
        }
        return ans;
    }
};
