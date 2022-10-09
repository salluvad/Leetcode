class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         vector<int> sortedQueries = queries;
        // we sort the intervals based on start times
        // we also sort the queries
        // need to maintain the relative position of queriers some where so we can return the result in correct order 
        // we need to return the min interval for a query , if we have multiples intervals for a query we need to return the smallest one 
        // so we need to maintain the intervals in the order and return the smallest one 
        // we need a min heap for that 
        // in the min heap along with the legth of min interval we need to store the Ending boundary of that interval .
        
        // we will pop these intervals from min heap only if the query is out of that boundary of top ele 
        
        unordered_map<int ,int> mp ; // Query and its min interval size 
        
        
        vector<int> res;
        
        //min heap for getting the smallest interval 
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        //sort the intervals and queries 
        sort(intervals.begin(),intervals.end());   // sort based on start times 
        sort(sortedQueries.begin(),sortedQueries.end());
        
        int j = 0;
        for(int i = 0 ; i<sortedQueries.size();i++){
            //for that query insert every interval in which it falls 
            while(j<intervals.size() and intervals[j][0]<=sortedQueries[i]){
                
                pq.push({intervals[j][1]-intervals[j][0]+1 , intervals[j][1]}) ; //push lenghth and ending val 
                 j++;
            }
            
            // we pop only if query is out of boun for top element 
            while(!pq.empty() && pq.top().second<sortedQueries[i])
            {
                pq.pop();
            }
            
            if (!pq.empty()) {
                mp[sortedQueries[i]] = pq.top().first;
            } else {
                mp[sortedQueries[i]] = -1;
            }
            
            
        }
        // push the hash map into our resul vector 
         for (int j = 0; j < queries.size(); j++) {
            res.push_back(mp[queries[j]]);
         }
        
        return res;
    }
};
