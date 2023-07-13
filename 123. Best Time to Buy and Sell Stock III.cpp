class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size() ;
        vector<vector<int>> next(3,vector<int>(2,0)) ;
        vector<vector<int>> curr(3,vector<int>(2,0)) ;

        for(int index = n-1 ; index>=0 ; index-- ){
            for (int max_count = 1 ; max_count<=2 ; max_count++){
                for (int buy = 0 ; buy<=1 ; buy++){
                    if(buy){
                        curr[max_count][buy]=max(-prices[index]+next[max_count][0] , next[max_count][1]) ;
                    }
                    else{
                        curr[max_count][buy]=max(prices[index]+next[max_count-1][1] , next[max_count][0] ) ;
                    }
                }
            }
            next = curr ;
        }
        return(curr[2][1]) ;        
    }
};