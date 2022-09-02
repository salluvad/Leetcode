
class Solution {
public:
    //same as aggressive cows probelm
    bool is_possible(vector<int>& pos , int minDist,int balls){
        int cnt_balls =1 ;
        int last_placed = pos[0];
        for(int i = 1 ; i<pos.size();i++){
            if(pos[i]-last_placed >=minDist){
                cnt_balls++;
                last_placed = pos[i];
            } 
            if(cnt_balls==balls){
               return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(position.begin(),position.end());
        int balls = m;
        int low = 1;
        int ans = -1;
        int high = position[n-1]-position[0];   // here low and high are minumDIst vwe can keep between balls , this is our monotonic search space
       
        while(low<=high){
            int mid = (low+high) >> 1;
            
            if(is_possible(position , mid,balls)){
                low = mid+1 ;
                ans = mid;
            } else {
                high = mid-1;
            }
        }
        return ans;
 
