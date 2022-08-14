class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int L = 0, R = matrix.size()-1;
        while(L<R){
            for(int i = 0 ; i<R-L;i++){
                int T=L;
                int B=R;
                int topleft = matrix[T][L+i];
                matrix[T][L+i] =  matrix[B-i][L];
                matrix[B-i][L] = matrix[B][R-i];
                matrix[B][R-i] = matrix[T+i][R];
                matrix[T+i][R] = topleft;
            }
            L++;
            R--;
        }
    }
}
