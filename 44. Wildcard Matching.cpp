class Solution {
public:
    bool func(int i , int j , string &s , string &p , vector<vector<int>> &dp){
        if(i<1 && j<1){
            return(true);
        }
        if (j<1){
            return(false);
        }
        if (dp[i][j]!=-1){
            return(dp[i][j]) ;
        }
        if (i<1){
            
            while(j!=0){
                if(p[j-1]!='*'){
                    return(false);
                }
                j--;
            }
            return(true);
        }

        if(s[i-1]==p[j-1]){
            return(dp[i][j]=func(i-1,j-1,s,p,dp));
        }
        else if(p[j-1]=='?'){
            return(dp[i][j] = func(i-1,j-1,s,p,dp));
        }
        else if(p[j-1]=='*'){
            return(dp[i][j] = func(i,j-1,s,p,dp)|| (func(i-1,j-1,s,p,dp) || func(i-1,j,s,p,dp)));
        }
        else {
            return(false);
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length() ;
        int m = p.length() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //dp[0][0] = true ;
        /*for (int i = 1 ; i<=m ; i++){
            dp[i][0] = false ;
        }*/
        return(func(n,m,s,p,dp));
    }
};