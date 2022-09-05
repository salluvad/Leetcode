/* The knows API is defined for you.
      bool knows(int a, int b); */

// two ways first making it a graph and calculate indegree and out degree of each node 
//return the node with indegree of N-1.  >>> O(n2)
//second is using a stack and eliminating candidates based knows(a,b) api >> o(n)

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> s;
        
        //first insert all elements into stack 0-n-1
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            
            //pop top two for comaprison/eliminatio 
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            //find if a knows b or not
            if(knows(a,b)){
                s.push(b);
            } else s.push(a);
        }
        
        int c=s.top();
        
        // we need to check c doesnt know any body or anybody doesn't know c
        
        for(int i = 0 ; i<n;i++){
            if(c!=i and (knows(c,i) || !knows(i,c)))
               return -1;
        }
               
               return c;
    }
};


>>>>> using graph

int findCelebrity(int n)
{
    //the graph needs not be constructed
    //as the edges can be found by
    //using knows function
     
    //degree array;
    int indegree[n]={0},outdegree[n]={0};
     
    //query for all edges
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x = knows(i,j);
             
            //set the degrees
            outdegree[i]+=x;
            indegree[j]+=x;
        }
    }
     
    //find a person with indegree n-1
    //and out degree 0
    for(int i=0; i<n; i++)
    if(indegree[i] == n-1 && outdegree[i] == 0)
        return i;
     
    return -1;
}
