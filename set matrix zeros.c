//O(1) space solution , neetcode logic 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we will use first col to indicte which  colms neded to be zeroed 
        //  and  one variable  row check to indicate that row needs to be zeroed        
        int rows = matrix.size();
        int cols = matrix[0].size();       
        bool firstRow=false; 
      
        for(int c=0;c<cols;c++) {
            if(matrix[0][c]==0) { // if anything in first row is zero , set the variable true
                firstRow=true;
            }
        }
        
        for(int r=1; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(matrix[r][c]==0)
                {
                   matrix[0][c]=0;    // we use first col to indicate that col to be zero
                }
            }
        }
  // second traversal       
        
        for(int r=1; r<rows;r++)
        {
            bool rowcheck=false; 
            
             for(int c=0;c<cols;c++)
               {
                 if(matrix[r][c]==0)
                 {
                     rowcheck=true;
                     break;
                 }
               }
            
            for(int c=0;c<cols;c++)
            {
                if(rowcheck ||  matrix[0][c]==0)
                    matrix[r][c]=0;
            }
        }
        
        if(firstRow)
        {
            for(int c=0;c<cols;c++)
                matrix[0][c]=0;
        }
        
    }
       
};
