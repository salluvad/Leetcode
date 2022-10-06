class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int src){
        visited[src] = 1;
        for(int i = 0 ;i<adjList[src].size();i++){
            if(visited[adjList[src][i]]==0){
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // from the edges we need to calc asj list 
        int components = 0 ;
        if (n ==0){
            return 0;
        }
        
        //adj list
        vector<int> adj[n];  
        for(int i= 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n,0);
        
        for(int i = 0 ;i<n;i++){
            if(vis[i]==0){
                components++;
                dfs(adj,vis,i);
            }
        }
        
      return  components; 
    }
};
