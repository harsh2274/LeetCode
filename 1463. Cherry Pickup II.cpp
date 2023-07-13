class Solution {
public:
    int traversal(int i , int j1 , int j2 , int n , int m , vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if (j1<0 || j2<0 || j1>=m || j2>=m){
            return(-1e8);
        }
        if(i==n-1){
            if(j1==j2){
                return(grid[i][j1]);
            }
                
            else{
                return(grid[i][j1] + grid[i][j2]) ; 
            }
        }

        if(dp[i][j1][j2]!=-1) return(dp[i][j1][j2]);

        int maxi = -1e8 ;
        for (int j_1 = -1 ; j_1<2 ; j_1++){
            for(int j_2 = -1 ; j_2<2 ; j_2++){
                if(j1==j2){
                    maxi = max(maxi , grid[i][j1] + traversal(i+1,j1+j_1,j2+j_2,n,m,grid,dp)) ;
                }
                else{
                    maxi = max(maxi , grid[i][j1] + grid[i][j2] + traversal(i+1,j1+j_1,j2+j_2,n,m,grid,dp)) ;
                }
            }
        }

        return(dp[i][j1][j2]=maxi);
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int i = 0  , j1 = 0 , j2 = grid[0].size()-1  ;
        int n = grid.size() ;
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(m,vector<int>(m,-1))) ;
        int temp = traversal(i,j1,j2,n,m,grid , dp);
        return(temp) ;
    }
};