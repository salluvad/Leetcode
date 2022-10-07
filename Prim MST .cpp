// steps
1. we need a parent array for printing the MST
2.We need a MST set to keep track of processed nodes
3.we need a dist/cost array to keep min costs
4.This is a greedy algorithm , so we pick the neighbors of lowest cost 

void findMST(int graph[V][V])
{
	int parent[V];		//Stores MST
	vector<int> value(V,INT_MAX);	//Used for edge relaxation
	vector<bool> setMST(V,false);	//TRUE->Vertex is included in MST
  
  //Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st
  
  //Form MST with (V-1) edges
	for(int i=0;i<V-1;++i)
	{ 
    //Select best Vertex by applying greedy method
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	//Include new Vertex in MST
    
    //Relax adjacent vertices (not yet included in MST)
		for(int j=0;j<V;++j)
		{
			/* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
      if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
      
    }
    for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
  }
