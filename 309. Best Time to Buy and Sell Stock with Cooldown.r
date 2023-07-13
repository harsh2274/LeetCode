class Solution {
public:

    int func(vector<int>& prices,int index,int buy,vector<vector<int>> dp){
        
        if (index >= prices.size() ){
            return(0) ;
        }
        if(dp[index][buy]!=-1){
            return(dp[index][buy]);
        }
        if(buy){
            return(dp[index][buy]=max(-prices[index]+func(prices,index+1,0,dp) , func(prices,index+1,1,dp) )) ;
        }
        else{
            return(dp[index][buy]=max(prices[index]+func(prices,index+2,1,dp) , func(prices,index+1,0,dp) )) ;
        }
    }
    int maxProfit(vector<int>& prices) {

         int n = prices.size() ;
        vector<vector<int>> dp(n+2,vector<int>(2,0)) ;
        for(int index = n-1 ; index>=0 ; index-- ){
            for (int buy = 0 ; buy<=1 ; buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0] , dp[index+1][1]) ;
                }
                else{
                    dp[index][buy]=max(prices[index]+dp[index+2][1] , dp[index+1][0] ) ;
                }
        
            }

        }
        return(dp[0][1]) ;        
    }
};