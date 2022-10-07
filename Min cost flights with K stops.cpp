///
https://leetcode.com/problems/cheapest-flights-within-k-stops/
////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we use bellman ford algo , kind of modified BFS 
        // for k stop s we run the loop k+1 times
        
        vector<int> cost(n,INT_MAX) ; // initailly distance to all destinations is empty
        
        //distance to src is Zero
        cost[src] = 0;
        
        for(int i = 0 ;i<=k;i++){
            //create a temp array 
            vector<int> temp(cost) ; // we use this as running array to calc imtermediate results 
            
            for(auto edge : flights){
                int u = edge[0];
                int v = edge[1];
                int c = edge[2]; //cost
                
                if(cost[u]!=INT_MAX){
                    temp[v] = min(temp[v],cost[u]+c);
                }
            }
            cost = temp;
        }
        return cost[dst] == INT_MAX ? -1:cost[dst];
    }
};
