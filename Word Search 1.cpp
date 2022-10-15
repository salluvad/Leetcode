// search for a word in a grid 


class Solution {
public:
      bool search(int i, int j, int m, int n, vector<vector<char>> &board, string &word, int k){
        if(k==word.size()) return true;   // lenght of word 
          //sanity check 
        if(i<0||j<0||i==m||j==n||board[i][j]!=word[k]) return false;
          // save the current char 
        char ch=board[i][j];
        board[i][j]='#';  // mark it visited  use some spl char
          
          //search in all directions        
        bool op1 = search(i+1,j,m,n,board,word,k+1);
        bool op2 = search(i-1,j,m,n,board,word,k+1);
        bool op3 = search(i,j+1,m,n,board,word,k+1);
        bool op4 = search(i,j-1,m,n,board,word,k+1);
          //after backtracking , replace the char 
        board[i][j]=ch;
          
        return (op1 || op2 || op3 || op4);
    }

  //DFS + bACK TRACKING       
    
    bool exist(vector<vector<char>>& board, string word) {
       int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){    // start from cells which match the staring of word
                   if (search(i,j,m,n,board,word,0)) return true;
                }
            }
        }
        return false;
    }
        

};
