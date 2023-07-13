class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for (int i = 0 ; i<=amount ; i++){
            if(i%coins[0]==0){
                 
                 prev[i] = 1 ;
            } 
        }
        prev[0] = 1 ;
        curr[0] = 1 ; 
        
        

        for (int index = 1 ; index<coins.size() ; index++){
            for(int V = 1 ; V <= amount ; V++){
                int nottake = prev[V];
                int take = 0 ;
                if(V>=coins[index]){
                    take = curr[V-(coins[index])];
                }
                curr[V] = nottake+take;
            }
            prev = curr ;
        }

        return(prev[amount]) ;
    }
};