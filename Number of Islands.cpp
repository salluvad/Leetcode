class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    //instead of visisted array , mark the grid valuse sto "0" to indicate it as visited
    int R = grid.size();
    if(R == 0) {
        return 0;
    }
    int C = grid[0].size();
    
    int total  = 0 ;
    
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c<C ; c++){
            if(grid[r][c] == '1'){
                total++;
                //mark as visited
                grid[r][c] = '0';
                queue<pair<int,int>> neighbors;
                neighbors.push({r,c});
                while(!neighbors.empty()){
                    auto rc = neighbors.front();
                    neighbors.pop();
                    int row = rc.first;
                    int col = rc.second;
                    //traverse all 4 directons  , and mark them as visisted 
                    if(row-1 >= 0 && grid[row-1][col]=='1'){
                        neighbors.push({row-1,col});
                        grid[row-1][col] = '0';
                    }
                    if (row + 1 < R && grid[row+1][col] == '1') {
                        neighbors.push({row+1, col}); 
                        grid[row+1][col] = '0';
                     }
                     if (col - 1 >= 0 && grid[row][col-1] == '1') {
                         neighbors.push({row, col-1}); 
                         grid[row][col-1] = '0';
                     }
                      if (col + 1 < C && grid[row][col+1] == '1') {
                          neighbors.push({row, col+1}); 
                          grid[row][col+1] = '0';
                     }
                }
            }
        }
    }
        return total ;
    }
};
