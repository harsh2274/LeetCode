class Solution {
public:
    int traversal(int i , int j ,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1 ;
        }

        if(i<0 || j<0){
            return 0 ;
        }

        if (dp[i][j]!=-1){
            return(dp[i][j]) ;
        }


        int up = traversal(i-1,j,dp) ;
        int left = traversal(i,j-1,dp) ;  
        return(dp[i][j] = up+left) ;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;
        //dp[m-1][n-1] = 1 ;
        return(traversal(m-1,n-1,dp));
        //return(dp[0][0]) ;
    }
};