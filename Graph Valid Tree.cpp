////////
You have a graph of n nodes labeled from 0 to n - 1. 
  You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge 
  between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

////////
class Solution {
public:
    bool dfs(vector<vector<int>>& adj,unordered_set<int>& vis,int src,int parent){
        //make it visited
        vis.insert(src);
        
        //loop through its neighbors
        for(auto it : adj[src]){
            if(vis.find(it)==vis.end()){
                dfs(adj,vis,it , src);
            } else if (it!=parent){
                return true ; //cycle found 
            }
        }
        return false ;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // Need to check two conditions 
        // No loops and no disconnected nodes 
        // we use dfs cycle detetcion and we maintain a set of vistsed nodes , finally size of set should be same as num of nodes 
        if(n == 0){
            return true  ; // empty grapg is a tree
        }
        
        //build a graph from edges 
       vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
       // create visited set
        unordered_set<int> vis;
        
        // use dfs to detect cycle , generally we run a dfs loop on all nodes if we have dis connectd graph
        //but here for a graph to be a tree there should be one component 
        // we can start at any node b/w 0-n-1 , we will start at zero 
        // in dfs cycle detection , we send a parent node to the func . 
        // for all the neighbors of node , if the node is visisted and its not same as parent then there is a cycle 
        
        return !dfs(adj,vis,0 ,-1) and (vis.size()==n);
    }
};
