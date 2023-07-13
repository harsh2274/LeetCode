class Solution {
public:
    double myPow(double x, int n) {
        double prod = 1.0 ;
        long i = n ;
        if(n==0){
            return(1.0000) ;
        }
        if (n>0){
            while(i>1){
                cout << i << "  " ;
                if (i%2==1){
                    i-- ;
                    prod = prod * x ;
                }
                else {
                    x = x * x ;
                    i = i/2 ; 
                }
                if (i==1){
                    break ;
                }
            }
            prod = prod * x ;
        }
        else {
            i=i*-1 ;
            while(i>1){
                cout << i << "  " ;
                if (i%2==1){
                    i-- ;
                    prod = prod * (1/x) ;
                }
                else {
                    x = x * x ;
                    i = i/2 ; 
                }
                if (i==1){
                    break ;
                }
            }
            prod = prod * (1/x) ;
        }
        return(prod) ;
    }
};