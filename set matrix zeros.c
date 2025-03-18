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


//// striver  we use col0 element 


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}


