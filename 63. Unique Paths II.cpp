class Solution {
public:

    int traversal(int i , int j ,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
        
        if(i<0 || j<0 || obstacleGrid[i][j]){
            return 0 ;
        }
        
        if(i==0 && j==0){
            return 1 ;
        }


        if (dp[i][j]!=-1){
            return(dp[i][j]) ;
        }


        int up = traversal(i-1,j,dp,obstacleGrid) ;
        int left = traversal(i,j-1,dp,obstacleGrid) ;  
        return(dp[i][j] = up+left) ;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;
        //dp[m-1][n-1] = 1 ;
        return(traversal(m-1,n-1,dp,obstacleGrid));
        //return(dp[0][0]) ;
    }
};