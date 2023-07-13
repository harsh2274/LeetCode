class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col ;
        set<int> row ;
        int row_siz = matrix.size() ;
        int col_siz = matrix[0].size() ;
        for (int i = 0 ; i< matrix.size() ; i++) {
            for (int j = 0 ; j<matrix[0].size() ; j++ ) {
                if (matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto it : row) {
            for (int j = 0 ; j< col_siz ; j++) {
                matrix[it][j] = 0 ;
            }
        }
        
        for (auto it : col) {
            for (int j = 0 ; j< row_siz ; j++) {
                matrix[j][it] = 0 ;
            }
        }
    }
};