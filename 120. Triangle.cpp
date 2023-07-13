class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       vector<vector<int>> vect(triangle.size(),vector<int>(triangle.size(),-99999));
       vect[0][0] = triangle[0][0] ;
       int mini = 99999;
       if(triangle.size()==1){
           return(triangle[0][0]);
       }
       for (int i = 1 ; i< triangle.size() ; i++ ){
           for(int j = 0 ; j<triangle[i].size(); j++){
               if(j==0){
                   vect[i][j] = vect[i-1][j]+triangle[i][j] ;
               }
               else if(j==triangle[i].size()-1){
                   vect[i][j] = vect[i-1][j-1]+triangle[i][j] ;
               }
               else {
                   vect[i][j] = min(vect[i-1][j]+triangle[i][j] , vect[i-1][j-1]+triangle[i][j]);
               }

               if(i==triangle.size()-1){
                    if(vect[triangle.size()-1][j]<mini){
                        mini = vect[triangle.size()-1][j] ;
                    }
               }
           }
       }
     
       return(mini) ;
    }
};