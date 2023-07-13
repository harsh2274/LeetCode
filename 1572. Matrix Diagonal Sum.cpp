class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumi = 0 ;
        for (int i = 0 ; i<mat.size() ; i++){
            sumi += mat[i][i] ;
        }
        int j = mat.size()-1 ;
        for (int i = 0 ; i<mat.size() ; i++){
            sumi += mat[i][j] ;
            j--;
        }
        if(mat.size()%2==1){
            sumi -= mat[mat.size()/2][mat.size()/2];
        }
        return(sumi) ;
    }
};