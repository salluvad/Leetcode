///
https://leetcode.com/problems/redundant-connection/
///


class Solution {
public:
    struct node{
        int parent;
        int rank;
    };
    vector<node> Union_find;
    
    int find(int v){
        if(Union_find[v].parent == -1){
            return v;
        } 
        return Union_find[v].parent = find( Union_find[v].parent);
    }
    
    void union_(int from , int to){
        //find the set with higher  rank and make it as parent 
        if(Union_find[from].rank > Union_find[to].rank){
            Union_find[to].parent = from;
        } else if(Union_find[from].rank < Union_find[to].rank){
            Union_find[from].parent = to;
        } else {
              // we can make anyone as parent
            Union_find[from].parent = to;
            Union_find[to].rank+=1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // union find algo for cycle detection 
        // Disjoint sets are reprsentd as trees ,and we use an array to describe child parent relation
        
        // initailly absolute parents of all the nodes is -1
        
        int n = edges.size() ;// given edges array is of size n and nodes are form 1 to n
        Union_find.resize(n+1);
        if(n==0){
            return {};
        }
         for(int i = 1 ; i<=n;i++){
             Union_find[i].parent = -1;
             Union_find[i].rank = 0;
         }
     
        vector<int> ans;
        
        //get each egde 
        for(auto edge:edges){
            int from =edge[0];
            int to = edge[1];
            
            int parent_of_from = find(from);
            int parent_of_to = find(to);
            
            if(parent_of_from == parent_of_to ){
                ans.clear();
                ans.push_back(from);
                ans.push_back(to);
            }
            
            else union_(parent_of_from,parent_of_to);
        }
        return ans;
    }
};
