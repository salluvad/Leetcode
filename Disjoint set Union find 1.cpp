//cycle detection  , we will be given an edge list [1,2] [2,3] [3,4] [4,1] 

/////
vector<int> dsuf;    // parent array 
//FIND operation
int find(int v)
{
	if(dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP,int toP)
{
	fromP = find(fromP);
	toP = find(toP);
	dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int,int>>& edge_List)
{
	for(auto p: edge_List)
	{
		int fromP = find(p.first);	//FIND absolute parent of subset
		int toP = find(p.second);

		if(fromP == toP)
			return true;

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
	}
	return false;
}
