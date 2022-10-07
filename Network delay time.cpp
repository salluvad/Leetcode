////
https://leetcode.com/problems/network-delay-time/

//////



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create a adj matrix
        vector<pair<int,int>> adj[n+1];
        
        for(auto time:times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        
        // keep an array to keep track of times when signal reaches the node
        vector<int> time(n+1, -1);
        
        //push the node  K in the queue  , node and Time t = 0
        queue<pair<int,int>> q;
        q.push({k,0});
        time[k] = 0;
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            
            int u = ele.first; // node
            int t = ele.second; //time
            
            for(auto ad:adj[u]){    // of type pair<int,int> 
                if(time[ad.first]==-1 or time[ad.first]>t+ad.second) {
                    time[ad.first] = t+ad.second;
                    q.push({ad.first,t+ad.second});
                }
            }
        }
        
        int ans = -1;
        for(int i=1; i<=n; i++) {
            ans = max(ans,time[i]);
            if(time[i]==-1)  {
                ans = -1;
                break;
            }
        }
        
        return ans;
    }
};
