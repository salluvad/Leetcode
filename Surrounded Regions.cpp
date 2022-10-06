///
https://leetcode.com/problems/surrounded-regions/

////



class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j , int &r , int &c){
        //boundary check
        if(i<0 or i>=r or j <0 or j>=c){
            return ;
        }
        if(board[i][j]=='O'){
            //if curr char is 'O'change it to 'T' and do dfs on all 4 dir 

            board[i][j] = 'T';

             dfs(board , i+1,j,r,c);
             dfs(board , i-1,j,r,c);
             dfs(board , i,j+1,r,c);
             dfs(board , i,j-1,r,c);
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        // initially we travel along the boundary of the grid and mark 'O' to some other char  'T'
        // and convert the island to those spl chars .
        
        //on second iteration convert remaining zeros to X , beacuse they are sourrounded by X's  and convert the spl char T to back to "O"
        
        if(board.size()==0){
            return ;
        }
        
        int r = board.size();
        int c = board[0].size();
        // first convert the boundary Zeors and their islands to spl char T
        for(int i = 0 ; i<r ; i++) {
            dfs(board , i ,0 , r ,c );  // first col and last col
             dfs(board , i ,c-1 ,r ,c );
        } 
        
         for(int i = 0 ; i<c ; i++) {
            dfs(board , 0 ,i,r,c);  // first row and last row
             dfs(board , r-1 ,i,r,c );
        } 
        
        for(int i = 0 ; i<r ; i++){
            for(int j= 0 ; j<c ; j++){
                //if its a border Zero or its island
                if(board[i][j]=='T'){
                    board[i][j]='O';
                } else if (board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
