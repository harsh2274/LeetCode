class Solution {
public:
    string removeTrailingZeros(string num) {
        string num2 = "" ;
        int flag = 0 ;
        
        
        for (int i = num.length()-1 ; i>0 ; i--){
            if (num[i]!='0'){
                flag = i ;
                break ;
            }
        }
        return(num.substr(0,flag+1));
    }
};