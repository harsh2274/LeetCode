class Solution {
public:
    bool ispalindrome(int i , int j , string &temp){
        while(i<j){
            if(temp[i]!=temp[j]){
                return(0);
            }
            i++ ;
            j-- ;
        }
        return(1);
    } 

   
    int minCut(string s) {
        vector<int> dp(s.length()+1,0);
        for(int index = s.length()-1 ; index>=0 ; index--){
            int maxi = 9999999 ;
            for(int j = index ; j<s.length() ; j++){
                if(ispalindrome(index,j,s)){
                    maxi = min(maxi,1 + dp[j+1]) ;
                }
            }
            dp[index]=maxi;
        }
        return(dp[0]-1);
    }
};