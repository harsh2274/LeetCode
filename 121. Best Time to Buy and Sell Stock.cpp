class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> back(prices.size()) ;
        int maxi = 0 ; 
        for (int i = prices.size()-1 ; i>-1 ; i--){
            if (prices[i]>maxi){
                maxi = prices[i] ;
            }
            back[i] = maxi ;
        }
        
        int maxi2 = 0 ;
        for (int i = 0 ; i<prices.size() ; i++) {
            if ((back[i]-prices[i])>maxi2){
                maxi2 = back[i]-prices[i] ; 
            }
        }
        return(maxi2) ;
    }
};