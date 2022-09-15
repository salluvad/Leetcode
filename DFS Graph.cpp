class Graph {
 
    // A function used by DFS
    void DFSUtil(int v);
 
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints DFS traversal of the complete graph
    void DFS();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}
 
// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
}




/////////////////
gfg submission 
/////////////////


class Solution {
    void dfs(int i ,vector<int> adj[],bool vis[],vector<int>& ans){
         //store it and mark it visi
         ans.push_back(i);
         vis[i] = true;
         for(auto it:adj[i]){
             if(!vis[it]){
                 dfs(it,adj,vis,ans);
             }
         }
         return;
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool vis[V];
        vector<int> ans;
        for(int i = 0 ;i<V;i++){
            vis[i]=0;
        }
         for(int i = 0 ;i<V;i++){
             if(!vis[i]){
                 dfs(i,adj,vis,ans);
             }
         }
        return ans;
        
    }
};
