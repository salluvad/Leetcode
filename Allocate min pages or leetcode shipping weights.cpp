class Solution {
    //https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/1576116/C%2B%2Bor-Binary-Search-on-Answers-(A-very-imp.-Topic)or-Easy-explanation
    //https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
public:
    bool is_possible(vector<int>&weights,int barrier,int days)
    {
        int running_weight=0;
        int day_cnt= 1;   // lets take example(2,3,4) and barrier as 9 . in the for loop sum is 9 and the if condition fails , we can ship all itme sin one day , so we made count as 1
        for(int i = 0 ; i<weights.size();i++){
            if(running_weight+weights[i]>barrier){
                day_cnt++;
                running_weight=weights[i];
                if(running_weight>barrier){
                    return false ;
                }
            } else {
                running_weight+=weights[i];
            }
        }
        if(day_cnt <= days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if(days>weights.size()){
            return -1;
        }
        
        int low = weights[0];
        int high = 0;
        int result=0;
        // our modified binary search space is low to high
        for (int i = 0; i < weights.size(); i++) {
             high = high + weights[i];
             low = min(low, weights[i]);
        }
        
        // we got low and high , start bnary search
        while(low<=high){
            int mid = low+high >>1;
            
            if(is_possible(weights,mid,days)){
                result = mid;
                high = mid-1;
            } 
            else {
                low = mid+1;
            }
        }
        return result;
    }
};
