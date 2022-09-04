//BFS and ornages rotten all the neighbours breadth wise 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;
        int r = grid.size();
        int c = grid[0].size();
        
        int vis[r][c];
 
        int tm = 0 ; // max time 
        
        queue<pair<pair<int,int>,int>> q;
        
        // start the bfs , go through the grid ans push all rotten orange positions in Q
        
        for(int i = 0 ;i<r;i++){
            for(int j = 0 ;j<c;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                } else vis[i][j] = 0;
            }
        }
        
        // define row and col deltas
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm ,t);
            q.pop();
            for(int i = 0 ; i<4;i++){
                int nrow= row+drow[i];
                int ncol= col+dcol[i];
                if(nrow>=0 and nrow<r and ncol>=0 and ncol<c and vis[nrow][ncol]!=2 and grid[nrow][ncol] ==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i = 0 ; i<r;i++){
            for(int j = 0 ; j<c;j++){
                if(vis[i][j]!=2 and grid[i][j]==1){
                    return -1;
                }
            }           
        }
        
        return tm;
                
        
    }
};
