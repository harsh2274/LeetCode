class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       vector<vector<int>> vect(matrix.size(),vector<int>(matrix.size(),99999));
       vect[0] = matrix[0] ;
       int mini = 99999;
       if(matrix.size()==1){
           return(matrix[0][0]);
       }

       for (int i = 1 ; i< matrix.size() ; i++ ){
           for(int j = 0 ; j<matrix[i].size(); j++){
               if(j==0){
                   vect[i][j] = min(vect[i-1][j]+matrix[i][j],vect[i-1][j+1]+matrix[i][j]) ;
               }
               else if(j==matrix[i].size()-1){
                   vect[i][j] = min(vect[i-1][j-1]+matrix[i][j],vect[i-1][j]+matrix[i][j]) ;
               }
               else {
                   vect[i][j] = min(vect[i-1][j]+matrix[i][j] , vect[i-1][j-1]+matrix[i][j]) ; 
                   vect[i][j] = min(vect[i][j] , vect[i-1][j+1]+matrix[i][j] );
               }

               if(i==matrix.size()-1){
                    if(vect[matrix.size()-1][j]<mini){
                        mini = vect[matrix.size()-1][j] ;
                    }
               }
           }
       }
     
       return(mini) ;
    }
};