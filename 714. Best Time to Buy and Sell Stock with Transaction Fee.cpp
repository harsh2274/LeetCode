class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<int> next(2,0) ;
        vector<int> curr(2,0) ;
        for(int index = n-1 ; index>=0 ; index-- ){
            for (int buy = 0 ; buy<=1 ; buy++){
                if(buy){
                    curr[buy]=max(-prices[index]+next[0]-fee , next[1]) ;
                }
                else{
                    curr[buy]=max(prices[index]+next[1] , next[0] ) ;
                }
            }
            next = curr ;
        }
        return(next[1]) ;        
    }
};