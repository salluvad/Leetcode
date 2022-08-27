class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starting;
        vector<int> ending;

        for (auto ele : intervals) {
            starting.push_back(ele[0]);
            ending.push_back(ele[1]);
        }

        sort(starting.begin(),starting.end());
        sort(ending.begin(),ending.end());

        int res = 1;
        int m_rooms = 1;
        int i1 = 1;
        int i2 = 0;

        while (i1 < starting.size() && i2 < ending.size()) {
            if (starting[i1] < ending[i2]) {
                m_rooms++;
                i1++;
            }
            else if(starting[i1] >= ending[i2]) {
                m_rooms--;
                i2++;
            }

            if(m_rooms>res){
                res = m_rooms;
            }
        }

        return res;
    }
        
    
}
