class Solution {
public:
    bool notInRow(vector<vector<char>> arr, int row)
      {
    // Set to store characters seen so far.
        set<char> st;
 
        for (int i = 0; i < 9; i++) {
 
        // If already encountered before, return false
        if (st.find(arr[row][i]) != st.end())
            return false;
 
        // If it is not an empty cell, insert value
        // at the current cell in the set
        if (arr[row][i] != '.')
            st.insert(arr[row][i]);
         }
      return true;
    }
 
// Checks whether there is any duplicate
// in current column or not.
bool notInCol(vector<vector<char>> arr, int col)
{
    set<char> st;
 
    for (int i = 0; i < 9; i++) {
 
        // If already encountered before, return false
        if (st.find(arr[i][col]) != st.end())
            return false;
 
        // If it is not an empty cell,
        // insert value at the current cell in the set
        if (arr[i][col] != '.')
            st.insert(arr[i][col]);
    }
    return true;
}
    
    bool notInBox(vector<vector<char>> arr, int startRow, int startCol)
{
    set<char> st;
 
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            char curr = arr[row + startRow][col + startCol];
 
            // If already encountered before, return false
            if (st.find(curr) != st.end())
                return false;
 
            // If it is not an empty cell,
            // insert value at current cell in set
            if (curr != '.')
                st.insert(curr);
        }
    }
    return true;
}
    
    bool isValid(vector<vector<char>> arr, int row, int col)
     {
          return notInRow(arr, row) && notInCol(arr, col) &&
                 notInBox(arr, row - row % 3, col - col % 3);
      }
   


    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
        
               if (!isValid(board,i,j)){
                  return false; 
               } 
           }
        }
        return true;
    }

    
};
