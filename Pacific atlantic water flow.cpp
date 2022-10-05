////

https://leetcode.com/problems/pacific-atlantic-water-flow/
////




class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j){
        //check of boundary conditions and check if previous cell height is greater than current one
        //since we are coming from ocean 
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // if we do it in abrute force way , we visit each cell and try finding out if it reaches any ocean 
        // we are doing a lot of repeated work , which gives us TLE 
        
        // better approach would be to start from the ocean and walk our backwards and each cell is 
        //visited  only once 
        
        //we maintain two visited sets /vectors ome for paciifc and one for atlantic
        //we do dfs from the oceans and add the elements to the sets , if we have element present in both sets we add it 
        //to result
        
        vector<vector<int>> ans;
        
        if(heights.size()==0){
            return ans;
        }
        
        int m = heights.size();
        if (m == 0)
            return ans;
        int n = heights[0].size();
         if (n == 0)
            return ans;
        
        vector<vector<bool>> pacific(m,vector<bool>(n,0));
        vector<vector<bool>> atlantic(m,vector<bool>(n,0));
        
        //start dfs from the edges
        for(int i = 0 ;i< m ;i++){
            dfs(heights,pacific,i,0);  //first col
            dfs(heights,atlantic,i,n-1);  // last col
        }
        
        for(int j = 0 ;j< n ;j++){
            dfs(heights,pacific,0,j);  //first row
            dfs(heights,atlantic,m-1,j);  // last row
        }
        
        //check if the cell is true in both pacific and atlantic
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
                    
            }
        }
        return ans;
        
    }
};
