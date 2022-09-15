class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // model it as a graph problem  , this is a classic topological sort
        // use Kahn BFS algo for topological sort
        // Kahns algo use indegree of the nodes 
        // calc indegree of all nodes and insert in Q if its indegree is zero 
        int V = numCourses;
     // build a graph from pre req
           
        vector<int> adj[numCourses];         // adj list        
        int edges = prerequisites.size();
        for(int i = 0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
     

        vector<int> indegree(V,0);
        queue<int> q;
        //calc. indegree
        for(int i =0 ; i<V;i++){
         for(auto it:adj[i]){
            indegree[it]++;
          }
        }
        //push the nodes with indegree 0
        for(int i = 0 ;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++;
            for(auto it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count == V){
            return true;
        } else return false;
    }
};
