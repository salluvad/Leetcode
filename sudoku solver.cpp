class Solution {
public:
bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;
    
    int startRow = row - row % 3 ;          /// these steps are easier to understnd than the one commented below
    int startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == c)
                return false;
    /*
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
      */
  }
  return true;
}    

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    return ;
}
    bool solve(vector<vector<char>>& board){
        // check for empty cell in the board 
   for (int i = 0; i < board.size(); i++) {
     for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; c++) {
             if (isValid(board, i, j, c)) {
                  board[i][j] = c;

              if (solve(board))
                  return true;
              else
                  board[i][j] = '.';
              }
            }
        return false;   // if we did not find a valid solution  with our current selection
      }
    }
  }
  return true;
    }
};
