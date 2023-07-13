class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = 999 ;
        int j =  0 ;
        for(int i = 0 ; i<prices.size() ; i++){
            if (prices[i]<first){
                first = prices[i];
                j = i ; 
            }
        }
        int second = 999;
        for(int i = 0 ; i<prices.size() ; i++){
            if (prices[i]<second and prices[i]>=first and i!=j ){
                second = prices[i];
            }
        }
        if ((first+second)<=money){
            return(money -(first+second) );
        }
        return(money);
        
    }
};