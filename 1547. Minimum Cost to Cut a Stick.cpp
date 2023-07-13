class Solution {
public:
    int func(vector<int>& cuts , int i , int j , vector<vector<int>> &dp){
        if(i>j){
            return(0) ;
        }

        int mini = 1e6 ;
        if(dp[i][j]!=-1){
            return(dp[i][j]) ;
        }
        for (auto k = i ; k<=j ; k++){
            cout << cuts[j] << "  " << cuts[i] << endl ; 
            int cost = cuts[j+1] - cuts[i-1] + func(cuts,i,k-1,dp) + func(cuts,k+1,j,dp) ;
            cout << cost << endl  ;
            if (cost<mini){
                mini = cost ;
            }  
        }
        return(dp[i][j] = mini) ;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n) ;
        int N = cuts.size() ;
        vector<vector<int>> dp(N, vector<int>(N,-1)) ;
        return(func(cuts,1,cuts.size()-2,dp));
    }
};