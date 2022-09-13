/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* src) {
        // we use BFS + map to clone . map is used to keep track of already created nodes 
        // so we dont run into infinte loops
        Node* node;
        queue<Node*> q;
        map<Node*,Node*> hm;
        if(src == NULL) 
        {
            return NULL;
        }
        q.push(src);
         
        node = new Node(src->val);
        hm[src] = node;
        
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            vector<Node*> v = u->neighbors;
            int n = v.size();
            for(int i = 0 ; i<n;i++){
                if(hm[v[i]]==0){
                    node = new Node(v[i]->val);
                    hm[v[i]]=node;
                    q.push(v[i]);
                }
                hm[u]->neighbors.push_back(hm[v[i]]);
            }
            
        }
        
       return hm[src]; 
    }
};
