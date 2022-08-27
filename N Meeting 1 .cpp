//return true or false if all n meetings can be scheduled in one room 


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& time) {
        sort(time.begin(),time.end());
        if(time.size() ==0){
            return true;
        }
        for(int i = 0 ; i<time.size()-1;i++){
            if(time[i][1]>time[i+1][0]){
                return false ;
            }
        }
        return true;
    }
};
